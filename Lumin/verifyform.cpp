#include "verifyform.h"

VerifyForm::VerifyForm(QWidget* parent):QWidget(parent) {
    QVBoxLayout* mainlayout = new QVBoxLayout(this);
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


    QLabel* textLabel = new QLabel;
    textLabel->setAlignment(Qt::AlignHCenter);
    textLabel->setFixedSize(420,50);

    QString email = "testemailabdef@gmail.com";

    email = email.right(14);

    QString textForMail = QString(
        "<div>"
        "<span style='font-family: 'Outfit';color: #666e6d; font-size: 16px;'>"
        "Enter the OTP (one time password) to verify your login.<br>"
        "A code has been sent to "
        "</span>"
        "<span style='color: #1a1b25;line-height: 150%; font-weight: 500; font-size: 14px;'>"
        "*******%1"
        "</span>"
        "</div>"
        ).arg(email);
    textLabel->setText(textForMail);

    MultipleEdit * multiEdit = new MultipleEdit(6);
    multiEdit->setFixedSize(420,70);

    QPushButton* verifyButton = new QPushButton("Verify", this);
    verifyButton->setFixedSize(420,52);
    verifyButton->setStyleSheet(
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
        "QPushButton:disabled {"
        "   background-color: #90cbb3;"
        "}"
        );
    verifyButton->setDisabled(true);

    connect(multiEdit, &MultipleEdit::allFilled, [verifyButton](bool cond){
        verifyButton->setDisabled(!cond);
    });


    QHBoxLayout* timeLayout = new QHBoxLayout;
    QLabel* timeLabel =  new QLabel;
    int totalSeconds = 90;
    QPushButton* reSendButton = new QPushButton;
    reSendButton->setText("Resend code");
    reSendButton->setFixedSize(165,20);
    reSendButton->setStyleSheet(
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
    reSendButton->setDisabled(true);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    QTimer *timer = new QTimer(this);
    QString text = QString("%1:%2")
                       .arg(minutes, 2, 10, QChar('0'))
                       .arg(seconds, 2, 10, QChar('0'));
    QString textForTime = QString("<div>"
                                  "<span style = ' color: #14201f; font-size: 14px; font-weight: 400;'>"
                                  "Time Remaining "
                                  "</span>"
                                  "<span style = ' color: #14201f; font-size: 14px; font-weight: 700;'>"
                                  "%1"
                                  "</span>"
                                  "<div>").arg(text);

    timeLabel->setText(textForTime);
connect(timer, &QTimer::timeout, this, [=]() mutable {
            totalSeconds--;

            minutes = totalSeconds / 60;
            seconds = totalSeconds % 60;

            text = QString("%1:%2")
                               .arg(minutes, 2, 10, QChar('0'))
                               .arg(seconds, 2, 10, QChar('0'));
            textForTime = QString("<div>"
                                          "<span style = ' color: #14201f; font-size: 14px; font-weight: 400;'>"
                                          "Time Remaining "
                                          "</span>"
                                          "<span style = ' color: #14201f; font-size: 14px; font-weight: 700;'>"
                                          "%1"
                                          "</span>"
                                          "<div>").arg(text);

            timeLabel->setText(textForTime);

            if (totalSeconds <= 0) {
                reSendButton->setDisabled(false);
                timer->stop();
            }
    });

    timer->start(1000);
    timeLabel->setFixedSize(160,20);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setStyleSheet(
        "   width: 160px;"
        "   height: 20px;"
        "   font-family: 'Outfit';"
        "   color: #666e6d;"
        "   font-size: 14px;"
        "   line-height: 120%;"
        "   font-weight: 400;"
        );


    timeLayout->addSpacing(50);
    timeLayout->addWidget(timeLabel);
    timeLayout->addWidget(reSendButton);
    timeLayout->addStretch();

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

    mainlayout->addWidget(helpButton,0,Qt::AlignRight);
    mainlayout->addStretch();
    mainlayout->addWidget(luminIconLabel);
    mainlayout->addWidget(headTextLabel);
    mainlayout->addWidget(textLabel);
    mainlayout->addSpacing(8);
    mainlayout->addWidget(multiEdit);
    mainlayout->addSpacing(8);
    mainlayout->addWidget(verifyButton);
    mainlayout->addSpacing(8);
    mainlayout->addLayout(timeLayout);
    mainlayout->addSpacing(8);
    mainlayout->addWidget(backToLoginButton);
    mainlayout->addStretch();
    mainlayout->addWidget(agreement);
}
