#ifndef PASSWORDHINTWIDGET_H
#define PASSWORDHINTWIDGET_H
#include <QVector>
#include <QFrame>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QString>

class PasswordHintWidget : public QWidget {
    Q_OBJECT

    struct Row{
        QString line;
        bool valid;
    };
    QVector<Row> rows;
    bool validEdit;
public:
    PasswordHintWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* event);
    bool validationUpdate(const QString& str);
};


#endif // PASSWORDHINTWIDGET_H
