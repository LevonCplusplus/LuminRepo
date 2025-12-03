#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QStatusBar>
#include<QPropertyAnimation>

#include "loginform.h"
#include "registerform.h"
#include "verifyform.h"
#include "successform.h"
#include "tokenmanager.h"
#include "apiclient.h"
#include "dashboard.h"
#include "resetpassform.h"
#include "loadingOverlay.h"

class MainWindow:public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void setStatusMessage(const QString& msg, const QColor& color = QColor("#333333"),int durationMs = 0);
    void resizeEvent(QResizeEvent* event)override;
public slots:
    void toVerify(const QString& maskedMail,const QString& sessionToken);
    void successShow(const QString& header,const QString& lowHeader,const QString& buttonText,User user);
private:
    QTimer* statusTimer;
    QLabel* statusLabel;
    LoadingOverlay* overlay;
    QWidget* centWidget;
    ApiClient* apiClient;
    QStackedWidget*  leftWidget;
    QHBoxLayout* mainLayout = new QHBoxLayout;
    LoginForm* loginForm;
    RegisterForm* registerForm;
    VerifyForm* verifyForm;
    SuccessForm* successForm;
    ResetPassForm* resetPassForm;
    Dashboard* dashboard;
    TokenManager* tokenManager;
    QLabel* labelForPhoto;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
