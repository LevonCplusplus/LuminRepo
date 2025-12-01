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
#include <QButtonGroup>
#include <QPainter>


class DashboardLeft: public QLabel{
    Q_OBJECT
public:
    DashboardLeft(QWidget* parent = nullptr);
//    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void dashboardPressed();
    void instructorsPressed();
    void transactionsPressed();
    void settingsPressed();
private:

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
    QLabel* iconLabel;
};

#endif // DASHBOARDLEFT_H
