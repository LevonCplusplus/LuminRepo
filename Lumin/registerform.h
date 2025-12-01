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
    void editsUpdate();

signals:
    void onloginClicked();
    void onCreateButtonClicked(const QString& first, const QString& last, const QString& mail, const QString& pass);

private:
    QLineEdit* firstNameEdit;
    QLineEdit* lastNameEdit;
    QLineEdit* emailEdit;
    QLineEdit* passwordEdit;
    QLineEdit* confirmEdit;
    QPushButton* createButton;
    PasswordHintWidget* hints;
};

#endif // REGISTERFORM_H
