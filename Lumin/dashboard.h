#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QPaintEvent>
#include <QPalette>
#include <QScrollArea>

#include "user.h"
#include "dashboardleft.h"
#include "dashboardcontent.h"
#include "settings.h"
#include "transactions.h"

class Dashboard: public QWidget{
    Q_OBJECT
public:
    Dashboard(User user,QWidget* parent = nullptr);
   // void paintEvent(QPaintEvent *event);
signals:
    void changingUserProfile(const QString& first,const QString& last);
private:
    User* user;
    DashboardLeft* dashboardLeft;
    Settings* settingsWidget;
    DashboardContent* dashboardContent;
    Transactions* transactions;

};

#endif // DASHBOARD_H
