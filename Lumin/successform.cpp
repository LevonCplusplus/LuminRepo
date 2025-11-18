#include "successform.h"

SuccessForm::SuccessForm(QWidget* parent):QWidget(parent) {

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* langLayout = new QHBoxLayout;
    mainLayout->addLayout(langLayout);

    this-> setStyleSheet("background-color: white");
    QPushButton* helpButton = new QPushButton(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout(helpButton);
    buttonLayout->setContentsMargins(16, 8, 12, 8);
    buttonLayout->setSpacing(0);

    QComboBox * language = new QComboBox;
    langLayout->addWidget(language);
    langLayout->addStretch();
    language->setFixedSize(176,48);
    language->setStyleSheet("QComboBox {"
                            "border-radius: 8px;"
                            "border:1px solid #eceff3;"
                            "padding-left:16px;"
                            "}"
                            "QComboBox::drop-down {"
                            "border:none;"
                            "margin-right: 16px;"
                            "}"
                            "QComboBox::down-arrow {"
                            "    image: url(:/images/downarrow.png);"
                            "    width: 12px;"
                            "    height: 12px;"
                            "}"
                            );
    QListView *view = new QListView;

    view->setStyleSheet(
        "QListView {"
        "   border: 1px solid #eceff3;"
        "   border-radius: 8px;"
        "   background: #ffffff;"
        "   outline: 0;"
        "}"
        "QListView::item {"
        "   border-radius: 8px;"
        "   padding: 8px 12px;"
        "   color: #14201f;"
        "   font-size: 14px;"
        "}"
        "QListView::item:selected {"
        "   background: #f0f4ff;"
        "   color: #0e66fe;"
        "}"
        );
    language->setView(view);

    QIcon englishIcon(":/images/english.png");
    QIcon russianIcon(":/images/russian.png");
    QIcon armenianIcon(":/images/armenian.png");
    language->addItem(englishIcon,"English");
    language->addItem(russianIcon,"Russian");
    language->addItem(armenianIcon,"Armenian");

    QLabel* iconLabel = new QLabel(this);
    QPixmap iconPixmap(":/images/help.png");
    iconLabel->setPixmap(iconPixmap.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap pix(":/images/successIcon.png");
    QPixmap sc = pix.scaled(172,162,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QLabel* successIconLabel = new QLabel;
    successIconLabel->setFixedSize(372,162);
    successIconLabel->setPixmap(sc);
    successIconLabel->setAlignment(Qt::AlignCenter);


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
    langLayout->addWidget(helpButton);
    /*****************************************
    if from reg registration Successfull
    else LoginSuccess

    *//****************************************/
    QLabel* headTextLabel = new QLabel("Login Success", this);
    headTextLabel->setFixedSize(372,35);
    headTextLabel->setStyleSheet(
        "font-family: 'Outfit';"
        "font-weight: 400;"
        "height: 29px;"
        "font-size: 24px;"
        "color: #14201F;"
        );
    headTextLabel->setAlignment(Qt::AlignHCenter);


    QLabel* textLabel = new QLabel("Welcome to Lumin, start exploring courses today.", this);
    textLabel->setAlignment(Qt::AlignHCenter);
    textLabel->setFixedSize(372,24);

    textLabel->setStyleSheet(
        "width: 372px;"
        "height: 24px;"
        "font-weight: 400;"
        "font-family: 'Outfit';"
        "color: #666e6d;"
        "font-size: 16px;"

        );
    QPushButton* startButton = new QPushButton("Start Learning", this);
    startButton->setFixedSize(372,52);
    startButton->setStyleSheet(
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


    mainLayout->addLayout(langLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(successIconLabel);
    mainLayout->addWidget(headTextLabel);
    mainLayout->addWidget(textLabel);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(startButton);
    mainLayout->addStretch();
    mainLayout->addWidget(agreement);

}
