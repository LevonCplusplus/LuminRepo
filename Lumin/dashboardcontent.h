#ifndef DASHBOARDCONTENT_H
#define DASHBOARDCONTENT_H
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>


class DashboardContent: public QLabel{
    Q_OBJECT
public:
    DashboardContent(QWidget* parent = nullptr);
    //void paintEvent(QPaintEvent *event);
    QWidget* createTotalWidget(const QString& str, QPixmap pix,int val, const QString& text);

};

#endif // DASHBOARDCONTENT_H
