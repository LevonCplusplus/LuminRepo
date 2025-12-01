#ifndef TOKENMANAGER_H
#define TOKENMANAGER_H
#include <QObject>
#include <QDateTime>

class TokenManager : public QObject {
    Q_OBJECT
public:
    TokenManager(QObject* parent = nullptr):QObject(parent){}
    QString accessToken() const { return m_accessToken; }
    QString refreshToken() const { return m_refreshToken; }

    void updateAccessToken(const QString& t) { m_accessToken = t; }
    void updateRefreshToken(const QString& t) { m_refreshToken = t; }

    bool isAccessExpired() const {
        return QDateTime::currentSecsSinceEpoch() > accessExpireTime;
    }

    void setAccessExpireTime(int seconds) {
        accessExpireTime = QDateTime::currentSecsSinceEpoch() + seconds;
    }

private:
    QString m_accessToken;
    QString m_refreshToken;
    long long accessExpireTime = 0;
};

#endif // TOKENMANAGER_H
