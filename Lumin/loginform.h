#ifndef LOGINFORM_H
#define LOGINFORM_H
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
#include <QCheckBox>
#include <QAction>

#include "registerform.h"
#include "verifyform.h"

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget* parent = nullptr);
public slots:
    void sendLogin();
signals:
    void registerButtonClicked();
    void onLoginClicked(const QString&,const QString&);
    void onForgotPasswordClicked();
protected:
    // void sendLogin();
private:
    QLineEdit* emailEdit;
    QLineEdit* passwordEdit;

};


#endif // LOGINFORM_H
