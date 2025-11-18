#include "loginform.h"

 LoginForm::LoginForm(QWidget* parent):QWidget(parent) {

    RegisterForm* regForm = new RegisterForm;
    setMinimumSize(900, 800);
    this->setStyleSheet("background-color: white;");

    mainLayout = new QHBoxLayout(this);
    QStackedWidget* stackedWidget = new QStackedWidget;
    mainLayout->addWidget(stackedWidget);

    QWidget* leftWidget = new QWidget(this);
    QVBoxLayout* loginLayout = new QVBoxLayout(leftWidget);

    QPushButton* helpButton = new QPushButton(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout(helpButton);
    buttonLayout->setContentsMargins(16, 8, 12, 8);
    buttonLayout->setSpacing(0);

    QLabel* iconLabel = new QLabel(this);
    QPixmap iconPixmap(":/images/help.png");
    iconLabel->setPixmap(iconPixmap.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap pix(":/images/luminIcon.png");
    QPixmap sc = pix.scaled(32,32,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QLabel* luminIconLabel = new QLabel;
    luminIconLabel->setFixedSize(420,32);
    luminIconLabel->setPixmap(sc);
    luminIconLabel->setAlignment(Qt::AlignCenter);


    QLabel* buttonLabel = new QLabel("Help", this);
    buttonLabel->setStyleSheet(
        "   font-family: 'Outfit';"
        "   font-size: 16px;"
        "   background-color: white;"
        );
    buttonLayout->addWidget(iconLabel);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(buttonLabel);
    helpButton->setLayout(buttonLayout);
    helpButton->setStyleSheet(
        "QPushButton {"
        "   height: 48px;"
        "   width: 93px;"
        "   border: 1px solid #eceff3;"
        "   border-radius: 8px;"
        "}"
        "QPushButton QLabel {"
        "   background-color: transparent;"
        "   border: none;"
        "   color: black;"
        "}"
        );

    QLabel* headTextLabel = new QLabel("Welcome back to Lumin", this);
    headTextLabel->setFixedSize(420,30);
    headTextLabel->setStyleSheet(
        "font-family: 'Outfit';"
        "font-weight: 400;"
        "height: 29px;"
        "font-size: 24px;"
        "color: #14201f;"
        );
    headTextLabel->setAlignment(Qt::AlignHCenter);


    QLabel* textLabel = new QLabel("Login with your email and password", this);
    textLabel->setAlignment(Qt::AlignHCenter);
    textLabel->setFixedSize(420,25);

    textLabel->setStyleSheet(
        "width: 420px;"
        "height: 24px;"
        "font-family: 'Outfit';"
        "color: #666e6d;"
        "font-size: 16px;"

        );

    QLabel* emailLabel = new QLabel("Email", this);
    emailLabel->setFixedSize(420,20);
    emailLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );
    QLineEdit* emailEdit = new QLineEdit(this);
    emailEdit->setPlaceholderText("Enter your Email");
    emailEdit->setFixedSize(420,48);
    emailEdit->setStyleSheet(
        "QLineEdit {"

        "   font-family: 'Outfit';"
        "   font-size: 16px;"
        "   font-weight: 400;"
        "   line-height: 150%;"
        "   letter-spacing: 0%;"
        "   color: #000000;"
        "   border: 1px solid #dfe1e7;"
        "   border-radius: 8px;"
        "   padding: 8px 12px;"
        "}"
        "QLineEdit::placeholder {"
        "   font-family: 'Outfit';"
        "   font-size: 16px;"
        "   font-weight: 400;"
        "   line-height: 150%;"
        "   letter-spacing: 0%;"
        "   color: #818898;"
        "}"
        );


    QLabel* passwordLabel = new QLabel("Password", this);
    passwordLabel->setFixedSize(420,20);
    passwordLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );

    QLineEdit* passwordEdit = new QLineEdit(this);
    passwordEdit->setFixedSize(420,48);
    passwordEdit->setStyleSheet(
            "QLineEdit {"
            "   font-family: 'Outfit';"
            "   font-size: 16px;"
            "   font-weight: 400;"
            "   line-height: 150%;"
            "   letter-spacing: 0%;"
            "   color: #000000;"
            "   border: 1px solid #dfe1e7;"
            "   border-radius: 8px;"
            "   padding: 8px 12px;"
            "}"
            "QLineEdit::placeholder {"
            "   font-family: 'Outfit';"
            "   font-size: 16px;"
            "   font-weight: 400;"
            "   line-height: 150%;"
            "   letter-spacing: 0%;"
            "   color: #818898;"
            "}"
        );
    passwordEdit->setPlaceholderText("Enter your Password");
    passwordEdit->setEchoMode(QLineEdit::Password);

    QWidget* remember = new QWidget;
    remember->setFixedSize(420,35);
    QHBoxLayout* rememberMeLayout = new QHBoxLayout;
    remember->setLayout(rememberMeLayout);

    QCheckBox* rememberMeButton = new QCheckBox;
    rememberMeButton->setText("Remember me");
    rememberMeButton->setFixedSize(130,24);

    rememberMeButton->setStyleSheet(
        "QCheckBox {"
        "   width: 92px;"
        "   height: 24px;"
        "   font-family: 'Outfit';"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        "   spacing: 5px;"
        "}"


        "QCheckBox::indicator {"
        "   width: 20px;"
        "   height: 20px;"
        "   border-radius: 6px;"
        "   border: 1px solid #eceff3;"
        "   background-color: white;"
        "}"

        "QCheckBox::indicator:hover {"
        "   border: 1px solid #a0a0a0;"
        "}"

        "QCheckBox::indicator:checked {"
        "   background-color: #0078d7;"
        "   border: 1px solid #0078d7;"
        "  image: url(:/images/check.png);"
        "}"
    );


    QPushButton* forgotButton = new QPushButton;
    forgotButton->setText("Forgot password?");
    forgotButton->setFixedSize(120,20);
    forgotButton->setStyleSheet(
        "QPushButton {"
        "   text-align: right;"
        "   border: none;"
        "   width: 113px;"
        "   height: 19px;"
        "   font-family: 'Outfit';"
        "   color: #0e66fe;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        "}"
        "QPushButton:hover {"
        "   text-decoration: underline;"
        "}"
        );

    rememberMeLayout->addWidget(rememberMeButton,0,Qt::AlignLeft);
    rememberMeLayout->addWidget(forgotButton,0,Qt::AlignRight);



    QPushButton* loginButton = new QPushButton("Login", this);
    loginButton->setFixedSize(420,52);
    loginButton->setStyleSheet(
        "QPushButton {"

        "   background-color: #499a79;"
        "   color: white;"
        "   border-radius: 8px;"
        "   border: 1px solid #ffffff;"
        "   padding: 8px 16px;"
        "   font-family: 'Outfit';"
        "   font-weight: 500;"
        "   font-size: 16px;"
        "   line-height: 20px;"
        "   letter-spacing: 1%;"
        "   text-align: center;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3b7d62;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #4da380;"
        "}"
        );

    connect(regForm,&RegisterForm::loginClicked,[stackedWidget](){
        stackedWidget->setCurrentIndex((stackedWidget->currentIndex() + 1) % 2);
    });

    QWidget* dontHaveWidget = new QWidget;
    QHBoxLayout* dontHaveLayout = new QHBoxLayout;
    dontHaveWidget->setLayout(dontHaveLayout);
    dontHaveWidget->setFixedSize(420,40);
    QLabel* dontHaveLabel = new QLabel("Don’t have an account ?");
    dontHaveLabel->setFixedSize(160,20);
    dontHaveLabel->setAlignment(Qt::AlignCenter);
    dontHaveLabel->setStyleSheet(
        "   width: 160px;"
        "   height: 19px;"
        "   font-family: 'Outfit';"
        "   color: #666e6d;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        );


    QPushButton* registerButton = new QPushButton;
    registerButton->setText("Register as an Instructor");
    registerButton->setFixedSize(165,20);
    registerButton->setStyleSheet(
        "QPushButton {"
        "   border: none;"
        "   width: 160px;"
        "   height: 19px;"
        "   font-family: 'Outfit';"
        "   color: #0e66fe;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        "}"
        "QPushButton:hover {"
        "   text-decoration: underline;"
        "}"
        );
    connect(registerButton,&QPushButton::clicked,[stackedWidget](){
        stackedWidget->setCurrentIndex((stackedWidget->currentIndex() + 1) % 2);
    });
    dontHaveLayout->addStretch();
    dontHaveLayout->addWidget(dontHaveLabel);
    dontHaveLayout->addWidget(registerButton);
    dontHaveLayout->addStretch();
    QLabel* agreement = new QLabel(this);

    agreement->setText(
        "By proceeding, you agree to our "
        "<a href=\"tos\" style=\"text-decoration:none; color:#0e66fe;\">Terms of Service</a>"
        " and "
        "<a href=\"privacy\" style=\"text-decoration:none; color:#0e66fe;\">Privacy Policy</a>."
        );

    agreement->setTextFormat(Qt::RichText);
    agreement->setTextInteractionFlags(Qt::TextBrowserInteraction);
    agreement->setOpenExternalLinks(false);
    agreement->setStyleSheet(
        "QLabel {"
        "   font-size: 13px;"
        "   color: #687076;"
        "}"
        "a:hover {"
        "   text-decoration: underline;"
        "}"
        );

    loginLayout->addWidget(helpButton,0,Qt::AlignRight);
    loginLayout->addStretch();
    loginLayout->addWidget(luminIconLabel,0,Qt::AlignHCenter);
    loginLayout->addWidget(headTextLabel,0,Qt::AlignHCenter);
    loginLayout->addWidget(textLabel,0,Qt::AlignHCenter);
    loginLayout->addWidget(emailLabel,0,Qt::AlignHCenter);
    loginLayout->addSpacing(8);
    loginLayout->addWidget(emailEdit,0,Qt::AlignHCenter);
    loginLayout->addSpacing(8);
    loginLayout->addWidget(passwordLabel,0,Qt::AlignHCenter);
    loginLayout->addSpacing(8);
    loginLayout->addWidget(passwordEdit,0,Qt::AlignHCenter);
    loginLayout->addWidget(remember,0,Qt::AlignHCenter);
    loginLayout->addSpacing(8);
    loginLayout->addWidget(loginButton,0,Qt::AlignHCenter);
    loginLayout->addSpacing(8);
    loginLayout->addWidget(dontHaveWidget,0,Qt::AlignHCenter);
    loginLayout->addStretch();
    loginLayout->addWidget(agreement,0,Qt::AlignHCenter);

    stackedWidget->addWidget(leftWidget);
    stackedWidget->addWidget(regForm);


    labelForPhoto = new QLabel(this);
    pixmap = QPixmap(":/images/Pasted image.png");
    mainLayout->addWidget(labelForPhoto);


}

 void LoginForm::resizeEvent(QResizeEvent* event)
 {
     qDebug() << "Entering resizeEvent, size:" << event->size();


     if (!pixmap.isNull() ) {
         QPixmap scaled = pixmap.scaled(
             size().width() / 2,
             size().height(),
             Qt::KeepAspectRatio,
             Qt::SmoothTransformation
             );
         labelForPhoto->setPixmap(scaled);
     }

     qDebug() << "Exiting resizeEvent";
 }
