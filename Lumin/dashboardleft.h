#ifndef DASHBOARDLEFT_H
#define DASHBOARDLEFT_H

#include <QStackedWidget>
#include <QResizeEvent>
#include <QDebug>
#include <QIcon>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>
#include <QPainter>


class DashboardLeft: public QWidget{

    struct ButtonInfo {
        QString text;
        QSize size;
    };

    QMap<QPushButton*, ButtonInfo> buttonStates;
    QPushButton* dashboardButton;
    QPushButton* instructorsButton;
    QPushButton* courcesButton;
    QPushButton* usersButton;
    QPushButton* transactionsButton;
    QPushButton* settingsButton;
    bool collapsed;

public:
    DashboardLeft(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);

};

#endif // DASHBOARDLEFT_H
