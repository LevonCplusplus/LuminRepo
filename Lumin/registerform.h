#ifndef REGISTERFORM_H
#define REGISTERFORM_H

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
#include <QCheckBox>
#include <QFrame>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>

#include"passwordhintwidget.h"


class RegisterForm: public QWidget{
    Q_OBJECT
public:
    RegisterForm(QWidget* parent = nullptr);
    bool eventFilter(QObject* obj, QEvent* event);
    void resizeEvent(QResizeEvent *event);

signals:
    void loginClicked();

private:
    QLineEdit* passwordEdit;
    PasswordHintWidget* hints;
};

#endif // REGISTERFORM_H
