#include "dashboardleft.h"
#include <QResizeEvent>

DashboardLeft::DashboardLeft(QWidget* parent): QLabel(parent) {
    resize(500,600);
    this->setStyleSheet(
        "   border: none;"
        "   background-color: #f3f5f7;"
        "   border-radius: 12px;"
        );
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    setFixedWidth(300);


    QWidget* leftHeaderWidget = new QWidget;
    QHBoxLayout* leftHeaderLayout = new QHBoxLayout;
    leftHeaderWidget->setLayout(leftHeaderLayout);
    leftHeaderWidget->setFixedSize(300,60);
    QPixmap luminPixmap(":/images/luminIcon.png");
    QPixmap scLumin = luminPixmap.scaled(32,32,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    iconLabel = new QLabel;
    iconLabel->setPixmap(scLumin);
    iconLabel->installEventFilter(this);

    QLabel* leftHeader = new QLabel("Lumin Admin Panel");
    leftHeader->setStyleSheet("font-family: 'Outfit';"
                              "font-weight: 600;"
                              "line-height: 150%;"
                              "letter-spacing: 0%;"
                              "font-size: 16px;"
                              );        setFixedWidth(300);
    for(auto btn : buttonStates.keys()) {
        btn->setText(buttonStates[btn].text);
        btn->setFixedSize(buttonStates[btn].size);
    }
    leftHeader->setFixedSize(170,20);


    QPushButton* collapseButton = new QPushButton;
    QPixmap collapsePixmap(":/images/collapse.png");
    QPixmap scCollapse = collapsePixmap.scaled(30,30,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    collapseButton->setIcon(QIcon(scCollapse));
    collapseButton->setIconSize(QSize(20,20));
    collapseButton->setFixedSize(45,45);
    collapseButton->setStyleSheet("border: none;");

    leftHeaderLayout->addWidget(iconLabel);
    leftHeaderLayout->addSpacing(1);
    leftHeaderLayout->addWidget(leftHeader);
    leftHeaderLayout->addStretch();
    leftHeaderLayout->addWidget(collapseButton,0,Qt::AlignRight);



    QWidget* toolBar = new QWidget;
    QVBoxLayout* toolBarLayout = new QVBoxLayout;
    toolBar->setLayout(toolBarLayout);

    dashboardButton = new QPushButton;
    dashboardButton->setCheckable(true);
    dashboardButton->setText("Dashboard");

    dashboardButton->setStyleSheet("QPushButton {"
                                   "border: none;"
                                   "color:  #666d80;"
                                   "text-align: left;"
                                   "padding-left: 4px;"
                                   "}"
                                   "QPushButton:checked{"
                                   "background-color: #ffffff;"
                                   "border:1px;"
                                   "border-right: 4px solid #499a79;"
                                   "border-radius: 8px;"
                                   "color: #499a79;"
                                   "}");

    dashboardButton->setFixedSize(270,36);
    connect(dashboardButton,&QPushButton::pressed,this,&DashboardLeft::dashboardPressed);
    QIcon dashboardIcon;


    QPixmap dashboardPix(":/images/dashcheck.png");
    QPainter dashboardPainter(&dashboardPix);
    dashboardPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    dashboardPainter.fillRect(dashboardPix.rect(), QColor("#666d80"));
    dashboardIcon.addPixmap(dashboardPix, QIcon::Normal, QIcon::Off);
    dashboardIcon.addPixmap(QPixmap(":/images/dashcheck.png"), QIcon::Normal, QIcon::On);
    dashboardButton->setIcon(dashboardIcon);

    instructorsButton = new QPushButton;
    instructorsButton->setCheckable(true);
    instructorsButton->setText("Instructors");
    instructorsButton->setStyleSheet("QPushButton {"
                                   "border: none;"
                                   "color:  #666d80;"
                                   "text-align: left;"
                                   "padding-left: 4px;"
                                   "}"
                                   "QPushButton:checked{"
                                   "background-color: #ffffff;"
                                   "border:1px;"
                                   "border-right: 4px solid #499a79;"
                                   "border-radius: 8px;"
                                   "color: #499a79;"
                                   "}");

    instructorsButton->setFixedSize(270,36);
    connect(instructorsButton,&QPushButton::pressed,this,&DashboardLeft::instructorsPressed);

    QIcon instructorsIcon;


    QPixmap instructorsPix(":/images/instructors.png");
    QPainter instructorsPainter(&instructorsPix);
    instructorsPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    instructorsPainter.fillRect(instructorsPix.rect(), QColor("#499a79"));
    instructorsIcon.addPixmap(instructorsPix, QIcon::Normal, QIcon::On);
    instructorsIcon.addPixmap(QPixmap(":/images/instructors.png"), QIcon::Normal, QIcon::Off);
    instructorsButton->setIcon(instructorsIcon);



    courcesButton = new QPushButton;
    courcesButton->setCheckable(true);
    courcesButton->setText("Cources");
    courcesButton->setStyleSheet("QPushButton {"
                                     "border: none;"
                                     "color:  #666d80;"
                                     "text-align: left;"
                                     "padding-left: 4px;"
                                     "}"
                                     "QPushButton:checked{"
                                     "background-color: #ffffff;"
                                     "border:1px;"
                                     "border-right: 4px solid #499a79;"
                                     "border-radius: 8px;"
                                     "color: #499a79;"
                                     "}");

    courcesButton->setFixedSize(270,36);
    QIcon courcesIcon;


    QPixmap courcesPix(":/images/cources.png");
    QPainter courcesPainter(&courcesPix);
    courcesPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    courcesPainter.fillRect(courcesPix.rect(), QColor("#499a79"));
    courcesIcon.addPixmap(courcesPix, QIcon::Normal, QIcon::On);
    courcesIcon.addPixmap(QPixmap(":/images/cources.png"), QIcon::Normal, QIcon::Off);
    courcesButton->setIcon(courcesIcon);

    usersButton = new QPushButton;
    usersButton->setCheckable(true);
    usersButton->setText("Users");
    usersButton->setStyleSheet("QPushButton {"
                                     "border: none;"
                                     "color:  #666d80;"
                                     "text-align: left;"
                                     "padding-left: 4px;"
                                     "}"
                                     "QPushButton:checked{"
                                     "background-color: #ffffff;"
                                     "border:1px;"
                                     "border-right: 4px solid #499a79;"
                                     "border-radius: 8px;"
                                     "color: #499a79;"
                                     "}");

    usersButton->setFixedSize(270,36);
    QIcon usersIcon;


    QPixmap usersPix(":/images/users.png");
    QPainter usersPainter(&usersPix);
    usersPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    usersPainter.fillRect(usersPix.rect(), QColor("#499a79"));
    usersIcon.addPixmap(usersPix, QIcon::Normal, QIcon::On);
    usersIcon.addPixmap(QPixmap(":/images/users.png"), QIcon::Normal, QIcon::Off);
    usersButton->setIcon(usersIcon);

    transactionsButton = new QPushButton;
    transactionsButton->setCheckable(true);
    transactionsButton->setText("Transactions");
    transactionsButton->setStyleSheet("QPushButton {"
                                     "border: none;"
                                     "color:  #666d80;"
                                     "text-align: left;"
                                     "padding-left: 4px;"
                                     "}"
                                     "QPushButton:checked{"
                                     "background-color: #ffffff;"
                                     "border:1px;"
                                     "border-right: 4px solid #499a79;"
                                     "border-radius: 8px;"
                                     "color: #499a79;"
                                     "}");


    transactionsButton->setFixedSize(270,36);
    connect(transactionsButton,&QPushButton::pressed,this,&DashboardLeft::transactionsPressed);

    QIcon transactionsIcon;


    QPixmap transactionsPix(":/images/transactions.png");
    QPainter transactionsPainter(&transactionsPix);
    transactionsPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    transactionsPainter.fillRect(transactionsPix.rect(), QColor("#499a79"));
    transactionsIcon.addPixmap(transactionsPix, QIcon::Normal, QIcon::On);
    transactionsIcon.addPixmap(QPixmap(":/images/transactions.png"), QIcon::Normal, QIcon::Off);
    transactionsButton->setIcon(transactionsIcon);

    settingsButton = new QPushButton;
    settingsButton->setCheckable(true);
    settingsButton->setText("Settings");
    settingsButton->setStyleSheet("QPushButton {"
                                     "border: none;"
                                     "color:  #666d80;"
                                     "text-align: left;"
                                     "padding-left: 4px;"
                                     "}"
                                     "QPushButton:checked{"
                                     "background-color: #ffffff;"
                                     "border:1px;"
                                     "border-right: 4px solid #499a79;"
                                     "border-radius: 8px;"
                                     "color: #499a79;"
                                     "}");

    settingsButton->setFixedSize(270,36);
    connect(settingsButton,&QPushButton::pressed,this,&DashboardLeft::settingsPressed);
    QIcon settingsIcon;


    QPixmap settingsPix(":/images/settings.png");
    QPainter settingsPainter(&settingsPix);
    settingsPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    settingsPainter.fillRect(settingsPix.rect(), QColor("#499a79"));
    settingsIcon.addPixmap(settingsPix, QIcon::Normal, QIcon::On);
    settingsIcon.addPixmap(QPixmap(":/images/settings.png"), QIcon::Normal, QIcon::Off);
    settingsButton->setIcon(settingsIcon);

    toolBarLayout->addWidget(dashboardButton);
    toolBarLayout->addWidget(instructorsButton);
    toolBarLayout->addWidget(courcesButton);
    toolBarLayout->addWidget(usersButton);
    toolBarLayout->addWidget(transactionsButton);
    toolBarLayout->addWidget(settingsButton);
    toolBarLayout->addStretch();

    QButtonGroup* group = new QButtonGroup(this);
    group->setExclusive(true);

    group->addButton(dashboardButton);
    group->addButton(instructorsButton);
    group->addButton(courcesButton);
    group->addButton(usersButton);
    group->addButton(transactionsButton);
    group->addButton(settingsButton);

    dashboardButton->setChecked(true);

    buttonStates[dashboardButton]   = { dashboardButton->text(), dashboardButton->size() };
    buttonStates[instructorsButton] = { instructorsButton->text(), instructorsButton->size() };
    buttonStates[courcesButton]     = { courcesButton->text(), courcesButton->size() };
    buttonStates[usersButton]       = { usersButton->text(), usersButton->size() };
    buttonStates[transactionsButton]= { transactionsButton->text(), transactionsButton->size() };
    buttonStates[settingsButton]    = { settingsButton->text(), settingsButton->size() };


    connect(collapseButton, &QPushButton::clicked, [this](){
        setFixedWidth(60);
        for(auto btn : buttonStates.keys()) {
            btn->setText("");
            btn->setFixedSize(28,36);
        }

    });

    mainLayout->addWidget(leftHeaderWidget,0,Qt::AlignLeft);
    mainLayout->addWidget(toolBar);


}
bool DashboardLeft::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == iconLabel && event->type() == QEvent::MouseButtonPress) {
        setFixedWidth(300);
        for(auto btn : buttonStates.keys()) {
            btn->setText(buttonStates[btn].text);
            btn->setFixedSize(buttonStates[btn].size);
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

// void DashboardLeft::paintEvent(QPaintEvent *event)
// {
//     QPainter Painter(this);
//     Painter.fillRect(rect(), QColor("#F3FfF7"));
// }


