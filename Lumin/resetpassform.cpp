#include "resetpassform.h"

ResetPassForm::ResetPassForm(QWidget* parent)
    :QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    this-> setStyleSheet("background-color: white");
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

    QLabel* headTextLabel = new QLabel("Verify Your Login", this);
    headTextLabel->setFixedSize(420,35);
    headTextLabel->setStyleSheet(
        "font-family: 'Outfit';"
        "font-weight: 400;"
        "height: 29px;"
        "font-size: 24px;"
        "color: #14201f;"
        );
    headTextLabel->setAlignment(Qt::AlignHCenter);


    QLabel* textLabel = new QLabel("Enter your Email address and a link would be sent to "
                                   "\nchange your account password.");
    textLabel->setAlignment(Qt::AlignHCenter);
    textLabel->setFixedSize(420,50);
    textLabel->setStyleSheet(
        "width: 420px;"
        "height: 16px;"
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
    QPushButton* sendButton = new QPushButton("Send Reset Link", this);
    sendButton->setFixedSize(420,52);
    sendButton->setStyleSheet(
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


    QPushButton* backToLoginButton = new QPushButton;
    backToLoginButton->setText("Back to Login page");
    backToLoginButton->setFixedSize(420,20);
    backToLoginButton->setStyleSheet(
        "QPushButton {"
        "   border: none;"
        "   width: 160px;"
        "   height: 20px;"
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

    connect(backToLoginButton, &QPushButton::clicked,[this](){
        emit onBackToLoginClicked();
    });

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
        // "   text-decoration: underline;"
        "}"
        );


    mainLayout->addWidget(helpButton,0,Qt::AlignRight);
    mainLayout->addStretch();
    mainLayout->addWidget(luminIconLabel,0,Qt::AlignHCenter);
    mainLayout->addWidget(headTextLabel,0,Qt::AlignHCenter);
    mainLayout->addWidget(textLabel,0,Qt::AlignHCenter);
    mainLayout->addWidget(emailLabel,0,Qt::AlignHCenter);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(emailEdit,0,Qt::AlignHCenter);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(sendButton,0,Qt::AlignHCenter);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(backToLoginButton,0,Qt::AlignHCenter);
    mainLayout->addStretch();
    mainLayout->addWidget(agreement,0,Qt::AlignHCenter);

}
