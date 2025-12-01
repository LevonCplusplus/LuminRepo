#include "dashboard.h"

Dashboard::Dashboard(User user1,QWidget* parent):QWidget(parent) {
    this->user = new User(std::move(user1));
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor("#f3f5f7"));
    this->setPalette(pal);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    dashboardLeft = new DashboardLeft;

    dashboardContent = new DashboardContent;
    transactions = new Transactions;

    settingsWidget = new Settings(user);
    settingsWidget->layout()->setContentsMargins(24, 24, 24, 24);

    connect(settingsWidget,&Settings::onSaveChangesClicked,[this](const QString& first,const QString& last,const QString& mail){
        emit changingUserProfile(first, last);
    });

    QScrollArea* settingsArea = new QScrollArea;
    settingsArea->setWidgetResizable(true);
    settingsArea->setContentsMargins(50,50,50,50);
    settingsArea->setWidget(settingsWidget);
    settingsArea->setFrameShape(QFrame::NoFrame);
    settingsArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    settingsArea->viewport()->setStyleSheet(R"(
    background-color: #ffffff;
    border: 1px solid #E2E2EE;
    border-radius: 12px;
)");

    QStackedWidget* rightWidget = new QStackedWidget;

    dashboardContent->setObjectName("dashboardContent");
    rightWidget->addWidget(dashboardContent);


    mainLayout->addWidget(dashboardLeft);
    rightWidget->addWidget(settingsArea);
    rightWidget->addWidget(transactions);
    rightWidget->setCurrentWidget(dashboardContent);


    mainLayout->addWidget(rightWidget);
    connect(dashboardLeft, &DashboardLeft::dashboardPressed,[rightWidget,this](){
       rightWidget->setCurrentWidget(dashboardContent);
    });
    connect(dashboardLeft, &DashboardLeft::settingsPressed,[rightWidget,settingsArea,this](){
        rightWidget->setCurrentWidget(settingsArea);
    });
    connect(dashboardLeft, &DashboardLeft::transactionsPressed,[rightWidget,this](){
        rightWidget->setCurrentWidget(transactions);
    });


}

