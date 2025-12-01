#ifndef VERIFYFORM_H
#define VERIFYFORM_H
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>

#include "multipleedit.h"


class VerifyForm: public QWidget{
    Q_OBJECT
signals:
    void onVerifyClicked(const QString& verCod,const QString& sessionToken);
    void onBackToLoginClicked();
    void onResendClicked();
public:
    VerifyForm(const QString& mail, const QString& sessionToken, QWidget * parent = nullptr);
    void sendTime(int totalSeconds);
    void updateVerify(const QString& mail, const QString& sessionToken);
private:
    QLabel* timeLabel;
    QPushButton* reSendButton;
    QString mail;
    QString sessionToken;

};

#endif // VERIFYFORM_H
