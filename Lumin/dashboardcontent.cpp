#include "dashboardcontent.h"

DashboardContent::DashboardContent(QWidget* parent):QLabel(parent) {

    this->setStyleSheet(
        "   border: 1px solid #eeeeee;"
        "   background-color: #ffffff;"
        "   border-radius: 12px;"
        );
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* header = new QLabel("Admin Dashboard");
    header->setStyleSheet(" font-family: 'Outfit';"
                          " border: none;"
                          " font-weight: 600;"
                          " font-size: 24px;"
                          " line-height: 150%;"
                          " letter-spacing: 0%;"
                          " color: #1b1b1b;");
    QLabel* lowHeader = new QLabel("Welcome back! Here’s on overview of your platform.");
    lowHeader->setStyleSheet(" font-family: 'Outfit';"
                          " font-weight: 400;"
                          " border: none;"
                          " font-size: 16px;"
                          " line-height: 150%;"
                          " letter-spacing: 0%;"
                          " color: #838383;");
    QHBoxLayout*  totalLayout = new QHBoxLayout;

    QWidget* instructorWidget = createTotalWidget("Total Instructor",QPixmap(":/images/instructors.png"),0,"0 pending verification");
    QWidget* courcesWidget = createTotalWidget("Total Cources",QPixmap(":/images/cources.png"),0,"0 active courses");
    QWidget* studentsWidget = createTotalWidget("Total Students",QPixmap(":/images/users.png"),0,"0 active students");
    QWidget* revenueWidget = createTotalWidget("Total Revenue",QPixmap(":/images/revenue.png"),0,"Courses revenue");

    totalLayout->addWidget(instructorWidget);
    totalLayout->addSpacing(24);
    totalLayout->addWidget(courcesWidget);
    totalLayout->addSpacing(24);
    totalLayout->addWidget(studentsWidget);
    totalLayout->addSpacing(24);
    totalLayout->addWidget(revenueWidget);
    totalLayout->addStretch();

    mainLayout->setContentsMargins(24,24,0,0);
    mainLayout->addWidget(header,0,Qt::AlignLeft);
    mainLayout->addWidget(lowHeader,0,Qt::AlignLeft);
    mainLayout->addSpacing(24);
    mainLayout->addLayout(totalLayout);
    mainLayout->addStretch();

}

QWidget* DashboardContent::createTotalWidget(const QString& str, QPixmap pix,int val, const QString& text){

    QWidget* wdg = new QWidget;

    QPixmap sc = pix.scaled(16,16,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPainter painter(&sc);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(sc.rect(), QColor("#111113"));
    painter.end();

    QVBoxLayout* mainLayout = new QVBoxLayout(wdg);
    QHBoxLayout* headerLayout = new QHBoxLayout;
    mainLayout->addLayout(headerLayout);
    QLabel* iconLabel = new QLabel;
    iconLabel->setFixedSize(32,32);
    iconLabel->setPixmap(sc);
    iconLabel->setStyleSheet("border-radius: 8px;"
                             "padding: 8px;");
    QLabel* header = new QLabel(str);
    header->setStyleSheet(" font-family: 'Outfit';"
                          " border: none;"
                          " font-weight: 500;"
                          " font-size: 16px;"
                          " line-height: 155%;"
                          " letter-spacing: 0%;"
                          " color: #111113;");
    header->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(iconLabel);
    headerLayout->addWidget(header);
    headerLayout->addStretch();

    mainLayout->addStretch();

    QLabel* valLabel;
    if(str == "Total Revenue")
        valLabel = new QLabel("$" + QString::number(val));
    else
        valLabel = new QLabel(QString::number(val));
    valLabel->setStyleSheet(" font-family: 'Outfit';"
                              " border: none;"
                              " font-weight: 400;"
                              " font-size: 32px;"
                              " line-height: 120%;"
                              " letter-spacing: 0%;"
                              " color: #111113;");
    QLabel* textLabel = new QLabel(text);
    textLabel->setStyleSheet(" font-family: 'Outfit';"
                            " border: none;"
                            " font-weight: 400;"
                            " font-size: 12px;"
                            " line-height: 155%;"
                            " letter-spacing: 0%;"
                            " color: #838383;");
    mainLayout->addWidget(valLabel,0,Qt::AlignLeft);
    mainLayout->addWidget(textLabel, 0, Qt::AlignLeft);
    wdg->setFixedSize(262,149);
    return wdg;

}

