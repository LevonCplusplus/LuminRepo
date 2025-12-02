#ifndef APICLIENT_H
#define APICLIENT_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>

#include "user.h"
#include "tokenmanager.h"

enum class LoginStatus{Success, Failure};

class ApiClient: public QObject{
    Q_OBJECT
public:
    ApiClient(TokenManager* man,QObject* parent = nullptr);
public slots:
    void loginRequest(const QString& mail,const QString& pass);
    void verifyRequest(const QString& verCod,const QString& sessionToken);
    void registerRequest(const QString& first,const QString& last,const QString& mail,const QString& pass);
    void updateProfileRequest(const QString& first,const QString& last);
    void doUpdateProfile(const QString& first, const QString& last);
    void refreshAccessToken();

signals:
    void loginResult(LoginStatus status,const QString& message,const QString& mail = nullptr,const QString& session = nullptr);
    void verifySuccess(User user);
    void tokenRefreshed();
    void authExpired();
    void refreshFailed();
private:
    QNetworkAccessManager* manager;
    TokenManager* tokenManager;
};

#endif // APICLIENT_H
