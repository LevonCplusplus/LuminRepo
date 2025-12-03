#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent) {

    statusTimer = new QTimer(this);
    setMinimumSize(900, 800);
    statusLabel = new QLabel(this);
    statusLabel->setStyleSheet(
        "color: white;"
        "background-color: #333333;"
        "padding: 4px 8px;"
        "border-radius: 4px;"
        );
    setStatusMessage("Logging in", QColor("#2196f3"),9000);

    overlay = new LoadingOverlay(this);
    this->setStyleSheet("background-color: white;");
    centWidget = new QWidget;
    this->setCentralWidget(new QStackedWidget);
    centralWidget()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    qobject_cast<QStackedWidget*>(centralWidget())->addWidget(centWidget);
    qobject_cast<QStackedWidget*>(centralWidget())->setCurrentWidget(centWidget);
    mainLayout = new QHBoxLayout;
    centWidget->setLayout(mainLayout);
    tokenManager = new TokenManager(this);
    apiClient = new ApiClient(tokenManager,this);

    leftWidget = new QStackedWidget;

    mainLayout->addWidget(leftWidget);
    loginForm = new LoginForm;
    registerForm = new RegisterForm;
    resetPassForm = new ResetPassForm;
    successForm = new SuccessForm("","","");
    labelForPhoto = new QLabel(centWidget);
    pixmap = QPixmap(":/images/Pasted image.png");
    mainLayout->addWidget(labelForPhoto);

    leftWidget->addWidget(loginForm);
    leftWidget->addWidget(registerForm);
    leftWidget->addWidget(resetPassForm);
    leftWidget->addWidget(successForm);

    connect(registerForm,&RegisterForm::onloginClicked,[this](){
        leftWidget->setCurrentWidget(loginForm);
    });
    connect(loginForm,&LoginForm::registerButtonClicked,[this](){
        leftWidget->setCurrentWidget(registerForm);
    });
    connect(resetPassForm,&ResetPassForm::onBackToLoginClicked,[this](){
        leftWidget->setCurrentWidget(loginForm);
    });

    connect(loginForm, &LoginForm::onLoginClicked,[this](const QString& mail,const QString& pass) {

        overlay->raise();
        overlay->start();
        apiClient->loginRequest(mail,pass);
    });
    connect(apiClient,&ApiClient::loginResult,[this](Status status,const QString& message,const QString& mail,const QString& session){
        overlay->stop();
        if(status == Status::Success){
            setStatusMessage("Login successful!", QColor("#4caf50"),5000);
            toVerify(mail,session);
        }else{
            setStatusMessage(message+"!", QColor("#f44336"),5000);
        }
    });
    connect(apiClient,&ApiClient::verifyResult,[this](Status status,User user){
        overlay->stop();
        if(status == Status::Success){
            this->successShow("Login Success","Welcome to Lumin, start exploring courses today.","Start Learning",user);
        }else{
            setStatusMessage("Incorrect verification code!", QColor("#f44336"),5000);
        }
    });
    //levonlevonvarosyan@gmail.com
    //Test.account.2025
    connect(loginForm,&LoginForm::onForgotPasswordClicked,[this](){
        leftWidget->setCurrentWidget(resetPassForm);
    });
    connect(registerForm, &RegisterForm::onCreateButtonClicked,apiClient,&ApiClient::registerRequest);
    connect(apiClient,&ApiClient::authExpired,[](){
        qDebug() << "token error";
    });
    statusLabel->raise();
}
void MainWindow::resizeEvent(QResizeEvent* event)
{
    if (!labelForPhoto) {
        return;
    }else if (!pixmap.isNull() ) {
        QPixmap scaled = pixmap.scaled(
            size().width() / 2,
            size().height(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );
        labelForPhoto->setPixmap(scaled);
    }
}
void MainWindow::toVerify(const QString& maskedMail,const QString& sessionToken){

    overlay->stop();
    verifyForm = new VerifyForm(maskedMail,sessionToken);
    connect(verifyForm,&VerifyForm::onBackToLoginClicked,[this](){
        leftWidget->setCurrentWidget(loginForm);
    });
    connect(verifyForm,&VerifyForm::onResendClicked,loginForm,&LoginForm::sendLogin);//????????????????
    connect(verifyForm,&VerifyForm::onVerifyClicked,[this](const QString& verCod, const QString& sessionToken){
        overlay->raise();
        overlay->start();
        apiClient->verifyRequest(verCod,sessionToken);
    });
    leftWidget->addWidget(verifyForm);
    leftWidget->setCurrentWidget(verifyForm);

}
void MainWindow::successShow(const QString& header,const QString& lowHeader,const QString& buttonText,User user = User()){
    if(header == "Login Success"){
        connect(successForm,&SuccessForm::onStartClicked,[this, user]()mutable{
            dashboard = new Dashboard(std::move(user));
            connect(dashboard,&Dashboard::changingUserProfile,[this](const QString& firstName,const QString& lastName){
                apiClient->updateProfileRequest(firstName,lastName);
            });
            qobject_cast<QStackedWidget*>(centralWidget())->addWidget(dashboard);
            qobject_cast<QStackedWidget*>(centralWidget())->setCurrentWidget(dashboard);
        });
    }
    successForm->formUpdate(header, lowHeader, buttonText);
    leftWidget->setCurrentWidget(successForm);
}

void MainWindow::setStatusMessage(const QString& msg, const QColor& color,int durationMs)
{
    statusLabel->setText(msg);
    statusLabel->adjustSize();

    statusLabel->raise();
    statusLabel->show();

    statusLabel->move(width() - statusLabel->width() - 20, height() - 40);
    statusLabel->setStyleSheet(QString(
                                   "QLabel { color: white; background-color: %1; padding: 4px 8px; border-radius: 4px; }"
                                   ).arg(color.name()));
    if (msg == "Logging in"){
        connect(statusTimer, &QTimer::timeout, [this]() {
            QString text = statusLabel->text();

            if (text.endsWith(QString(3, '.'))) {
                statusLabel->setText(text.left(text.size() - 3));
            }
            else {
                statusLabel->setText(text + '.');
            }

            statusLabel->adjustSize();
        });
        statusTimer->start(400);
    }

    if (durationMs > 0) {
        QTimer::singleShot(durationMs, this, [this]() {
            statusTimer->stop();
            statusLabel->hide();
        });
    }
}
