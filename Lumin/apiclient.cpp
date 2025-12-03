#include "apiclient.h"

ApiClient::ApiClient(TokenManager* man, QObject* parent)
    :QObject(parent),manager(new QNetworkAccessManager(this)),tokenManager(man){

}
void ApiClient::loginRequest(const QString& mail, const QString& pass){

    QUrl url("https://learning-dashboard-rouge.vercel.app/api/auth/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["email"] = mail;
    json["password"] = pass;

    QJsonDocument doc(json);
    QByteArray requestData = doc.toJson();
    QNetworkReply* reply = manager->post(request,requestData);

    connect(reply, &QNetworkReply::finished, [reply,this]() {
        QByteArray response = reply->readAll();
        qDebug() << "Server reply:" << response;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject obj = jsonDoc.object();

        bool success = obj["success"].toBool();
        QString message = obj["message"].toString();
        if(success){
           QJsonObject data = obj["data"].toObject();
           QString mail = data["maskedEmail"].toString();
           QString session = data["sessionToken"].toString();
           emit loginResult(Status::Success,message,mail,session);
        }else{
            emit loginResult(Status::Failure,message);
        }
        qDebug() << "Success:" << success;
        qDebug() << "Message:" << message;

        reply->deleteLater();
    });

}
void ApiClient::verifyRequest(const QString& verCod,const QString& sessionToken){
    QUrl url("https://learning-dashboard-rouge.vercel.app/api/auth/verify-login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json" );
    QJsonObject obj;
    obj["sessionToken"] = sessionToken;
    obj["code"] = verCod;
    QJsonDocument doc(obj);
    QByteArray requestdata  = doc.toJson();
    QNetworkReply* reply = manager->post(request,requestdata);
    connect(reply,&QNetworkReply::finished,[reply,this](){
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);
        QJsonObject obj = doc.object();

        bool success = obj["success"].toBool();
        if(success){
            QJsonObject dataObj = obj["data"].toObject();
            QString accessToken = dataObj["accessToken"].toString();
            QString refreshToken = dataObj["refreshToken"].toString();
            QJsonObject userObj = dataObj["user"].toObject();
            QString userId = userObj["id"].toString();
            QString email = userObj["email"].toString();
            QString firstName = userObj["firstName"].toString();
            QString lastName = userObj["lastName"].toString();
            QString role = userObj["role"].toString();
            User user(userId,firstName,lastName,email,role);

            tokenManager->updateAccessToken(accessToken);
            tokenManager->updateRefreshToken(refreshToken);

            emit verifyResult(Status::Success,user);
        }else{
            emit verifyResult(Status::Failure);
        }

        reply->deleteLater();
    });

}


void ApiClient::registerRequest(const QString& first,const QString& last,const QString& mail,const QString& pass){
    QUrl url("https://learning-dashboard-rouge.vercel.app/api/auth/register");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QJsonObject obj;
    obj["firstName"] = first;
    obj["lastName"] = last;
    obj["email"] = mail;
    obj["password"] = pass;
    QJsonDocument doc(obj);
    QByteArray requestdata = doc.toJson();

    QNetworkReply* reply = manager->post(request,requestdata);

    connect(reply, &QNetworkReply::finished, [this,reply](){
        QByteArray response = reply->readAll();
        QJsonDocument respDoc = QJsonDocument::fromJson(response);
        QJsonObject respObj = respDoc.object();
        bool success = respObj["success"].toBool();
        QString message = respObj["message"].toString();

        if(success){
            QJsonObject data = respObj["data"].toObject();
            QString userId = data["userId"].toString();
            QString email = data["email"].toString();
            QString instructorStatus = data["instructorStatus"].toString();

            qDebug() << "Success:" << success;
            qDebug() << "userId:" << userId;
            qDebug() << "email:" << email;
            qDebug() << "instructorStatus:" << instructorStatus;


        }

    });

}

void ApiClient::doUpdateProfile(const QString& first, const QString& last)
{
    QUrl url("https://learning-dashboard-rouge.vercel.app/api/user/profile");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization",
                         "Bearer " + tokenManager->accessToken().toUtf8());

    QJsonObject body;
    body["firstName"] = first;
    body["lastName"]  = last;

    QNetworkReply* reply = manager->put(request, QJsonDocument(body).toJson());
    qDebug() << "do update mtela";
    connect(reply, &QNetworkReply::finished, this, [reply]() {

        auto json = QJsonDocument::fromJson(reply->readAll()).object();

        qDebug() << "Success:" << json["success"].toBool();
        qDebug() << "Message:" << json["message"].toString();

        reply->deleteLater();
    });
}
void ApiClient::updateProfileRequest(const QString& first, const QString& last)
{
    if (tokenManager->isAccessExpired()) {
        connect(this, &ApiClient::tokenRefreshed,[this, first, last]() {
                    doUpdateProfile(first, last);
                });
        qDebug()<<"access token miss";
        connect(this, &ApiClient::refreshFailed, this, [this]() {
            emit authExpired();
        });

        refreshAccessToken();
        return;
    }
    qDebug()<<"access token hit";

    doUpdateProfile(first, last);
}


void ApiClient::refreshAccessToken()
{
    QJsonObject obj;
    obj["refreshToken"] = tokenManager->refreshToken();
    qDebug() << "refreshToken == " <<  tokenManager->refreshToken();
    qDebug() << "accessToken == " <<  tokenManager->accessToken();
    QNetworkRequest req(QUrl("https://learning-dashboard-rouge.vercel.app/api/auth/refresh"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* rep = manager->post(req, QJsonDocument(obj).toJson());

    connect(rep, &QNetworkReply::finished, this, [this, rep]() {

        if (rep->error() != QNetworkReply::NoError) {
            emit refreshFailed();
            rep->deleteLater();
            return;
        }

        auto json = QJsonDocument::fromJson(rep->readAll()).object();
        QString newToken = json["data"].toObject()["accessToken"].toString();
        qDebug() << "newToken == " <<  tokenManager->refreshToken();
        tokenManager->updateAccessToken(newToken);
        tokenManager->setAccessExpireTime(3600);

        emit tokenRefreshed();

        rep->deleteLater();
    });
}

