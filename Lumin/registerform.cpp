#include "registerform.h"

RegisterForm::RegisterForm(QWidget* parent): QWidget(parent) {
    this->setStyleSheet("background-color: white;");
    QVBoxLayout* registerLayout = new QVBoxLayout(this);

    QPushButton* helpButton = new QPushButton;
    QHBoxLayout* buttonLayout = new QHBoxLayout(helpButton);
    buttonLayout->setContentsMargins(16, 8, 12, 8);
    buttonLayout->setSpacing(0);

    QLabel* iconLabel = new QLabel(this);
    QPixmap iconPixmap(":/images/help.png");
    iconLabel->setPixmap(iconPixmap.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation));

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

    QPixmap pix(":/images/luminIcon.png");
    QPixmap sc = pix.scaled(32,32,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QLabel* luminIconLabel = new QLabel;
    luminIconLabel->setFixedSize(420,32);
    luminIconLabel->setPixmap(sc);
    luminIconLabel->setAlignment(Qt::AlignCenter);

    QLabel* headTextLabel = new QLabel("Get started with Lumin!", this);
    headTextLabel->setFixedSize(420,29);
    headTextLabel->setStyleSheet(
        "font-family: 'Outfit';"
        "font-weight: 400;"
        "height: 29px;"
        "font-size: 24px;"
        "color: #14201f;"
        );
    headTextLabel->setAlignment(Qt::AlignHCenter);

    QLabel* textLabel = new QLabel("Start your learning journey with access to "
                                   "\ncourses, progress tracking, and certificates.", this);
    textLabel->setAlignment(Qt::AlignHCenter);
    textLabel->setFixedSize(420,60);
    textLabel->setStyleSheet(
        "width: 420px;"
        "height: 24px;"
        "font-family: 'Outfit';"
        "color: #666e6d;"
        "font-size: 16px;"

        );

    QLabel* firstNameLabel = new QLabel("First Name", this);
    firstNameLabel->setFixedWidth(420);
    firstNameLabel->setFixedHeight(20);
    firstNameLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );
    firstNameEdit = new QLineEdit(this);
    firstNameEdit->setPlaceholderText("First Name");
    firstNameEdit->setFixedSize(420,48);
    firstNameEdit->setStyleSheet(
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
    QLabel* lastNameLabel = new QLabel("Last Name", this);
    lastNameLabel->setFixedWidth(420);
    lastNameLabel->setFixedHeight(20);
    lastNameLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );
    lastNameEdit = new QLineEdit(this);
    lastNameEdit->setPlaceholderText("Last Name");
    lastNameEdit->setFixedSize(420,50);
    lastNameEdit->setStyleSheet(
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
    QLabel* emailLabel = new QLabel("Email", this);
    emailLabel->setFixedWidth(420);
    emailLabel->setFixedHeight(20);
    emailLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );
    emailEdit = new QLineEdit(this);
    emailEdit->setPlaceholderText("Enter your email address");
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
    passwordLabel->setFixedWidth(420);
    passwordLabel->setFixedHeight(20);
    passwordLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );

    passwordEdit = new QLineEdit(this);
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
    passwordEdit->installEventFilter(this);

    QAction *togglePasswordAction = new QAction(passwordEdit);

    togglePasswordAction->setIcon(QIcon(":/images/eye_closed.png"));
    togglePasswordAction->setToolTip("Show password");

    passwordEdit->addAction(togglePasswordAction, QLineEdit::TrailingPosition);

    connect(togglePasswordAction, &QAction::triggered, [this, togglePasswordAction]() {
        if (passwordEdit->echoMode() == QLineEdit::Password) {
            passwordEdit->setEchoMode(QLineEdit::Normal);

            togglePasswordAction->setIcon(QIcon(":/images/eye_open.png"));

            togglePasswordAction->setToolTip("Hide password");
        } else {
            passwordEdit->setEchoMode(QLineEdit::Password);

            togglePasswordAction->setIcon(QIcon(":/images/eye_closed.png"));

            togglePasswordAction->setToolTip("Show password");
        }
    });


    hints = new PasswordHintWidget(this);
    hints->hide();



    QLabel* confirmLabel = new QLabel("Confirm Password", this);
    confirmLabel->setFixedWidth(420);
    confirmLabel->setFixedHeight(20);
    confirmLabel->setStyleSheet(
        "font-family: 'Inter Tight';"
        "font-size: 14px;"
        "color: #000000;"
        );

    confirmEdit = new QLineEdit(this);
    confirmEdit->setFixedSize(420,48);
    confirmEdit->setStyleSheet(
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
    confirmEdit->setPlaceholderText("Confirm your Password");
    confirmEdit->setEchoMode(QLineEdit::Password);

    QAction *toggleConfirmAction = new QAction(passwordEdit);

    toggleConfirmAction->setIcon(QIcon(":/images/eye_closed.png"));
    toggleConfirmAction->setToolTip("Show password");

    confirmEdit->addAction(toggleConfirmAction, QLineEdit::TrailingPosition);

    connect(toggleConfirmAction, &QAction::triggered, [this, toggleConfirmAction]() {
        if (confirmEdit->echoMode() == QLineEdit::Password) {
            confirmEdit->setEchoMode(QLineEdit::Normal);

            toggleConfirmAction->setIcon(QIcon(":/images/eye_open.png"));

            toggleConfirmAction->setToolTip("Hide password");
        } else {
            confirmEdit->setEchoMode(QLineEdit::Password);

            toggleConfirmAction->setIcon(QIcon(":/images/eye_closed.png"));

            toggleConfirmAction->setToolTip("Show password");
        }
    });



    createButton = new QPushButton("Create Account", this);
    createButton->setFixedSize(420,52);
    createButton->setStyleSheet(
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
    createButton->setDisabled(true);
    connect(passwordEdit, &QLineEdit::textChanged, [this](){
        editsUpdate();
    });

    connect(confirmEdit, &QLineEdit::textChanged, [this](){
        editsUpdate();
    });

    connect(createButton, &QPushButton::clicked,[this](){
        emit onCreateButtonClicked(firstNameEdit->text(),lastNameEdit->text(),
                                   emailEdit->text(),passwordEdit->text());
    });

    QWidget* alreadyWidget = new QWidget;
    alreadyWidget->setFixedSize(420,40);
    QHBoxLayout* alreadyLayout = new QHBoxLayout;
    alreadyWidget->setLayout(alreadyLayout);
    QLabel* alreadyLabel =  new QLabel("Already have an account ?");
    alreadyLabel->setAlignment(Qt::AlignCenter);
    alreadyLabel->setStyleSheet(
        "   width: 149px;"
        "   height: 17px;"
        "   font-family: 'Outfit';"
        "   color: #666e6d;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        );


    QPushButton* loginButton = new QPushButton;
    loginButton->setFixedSize(40,20);
    loginButton->setText("Login");
    loginButton->setStyleSheet(
        "QPushButton {"
        "   border: none;"
        "   width: 35px;"
        "   height: 17px;"
        "   font-family: 'Outfit';"
        "   color: #0e66fe;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        "}"
        "QPushButton:hover{"
        "   text-decoration: underline;"
        "}"
        );
    connect(loginButton, &QPushButton::clicked, [this](){
        emit onloginClicked();
    });

    alreadyLayout->addStretch();
    alreadyLayout->addWidget(alreadyLabel);
    alreadyLayout->addWidget(loginButton);
    alreadyLayout->addStretch();
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
        "   text-decoration: none;"
        "}"
        );


    registerLayout->addWidget(helpButton,0,Qt::AlignRight);
    registerLayout->addStretch();
    registerLayout->addWidget(luminIconLabel,0,Qt::AlignCenter);
    registerLayout->addWidget(headTextLabel,0,Qt::AlignCenter);
    registerLayout->addWidget(textLabel,0,Qt::AlignCenter);
    registerLayout->addWidget(firstNameLabel,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(firstNameEdit,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(lastNameLabel,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(lastNameEdit,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(emailLabel,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(emailEdit,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(passwordLabel,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(passwordEdit,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(confirmLabel,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(confirmEdit,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(createButton,0,Qt::AlignCenter);
    registerLayout->addSpacing(8);
    registerLayout->addWidget(alreadyWidget,0,Qt::AlignCenter);
    registerLayout->addStretch();
    registerLayout->addWidget(agreement,0,Qt::AlignCenter);

}
bool RegisterForm::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == passwordEdit && event->type() == QEvent::FocusIn) {
        hints->show();
        update();
    }
    if (obj == passwordEdit && event->type() == QEvent::FocusOut) {
       hints->hide();
        update();
    }

    return QWidget::eventFilter(obj, event);
}

void  RegisterForm::resizeEvent(QResizeEvent* ){

    hints->move(passwordEdit->pos().x() - 6,passwordEdit->pos().y() - hints->size().height() - 20);

}

void RegisterForm::editsUpdate(){

    if(!confirmEdit->text().isEmpty() &&
        confirmEdit->text() != passwordEdit->text().left(confirmEdit->text().length())){

        confirmEdit->setStyleSheet(
            "QLineEdit {"
            "   font-family: 'Outfit';"
            "   font-size: 16px;"
            "   font-weight: 400;"
            "   line-height: 150%;"
            "   letter-spacing: 0%;"
            "   color: #000000;"
            "   border: 1px solid #d73e3d;"
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

    }
    else{
        confirmEdit->setStyleSheet(
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

    }



    bool val = hints->validationUpdate(passwordEdit->text());
    if(!(passwordEdit->text().isEmpty() || val)){
        passwordEdit->setStyleSheet(
            "QLineEdit {"
            "   font-family: 'Outfit';"
            "   font-size: 16px;"
            "   font-weight: 400;"
            "   line-height: 150%;"
            "   letter-spacing: 0%;"
            "   color: #000000;"
            "   border: 1px solid #d73e3d;"
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
    }
    else{
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
    }
    createButton->setDisabled(!(val && passwordEdit->text() == confirmEdit->text()));
    hints->update();

}





