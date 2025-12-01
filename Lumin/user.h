#ifndef USER_H
#define USER_H
#include <QString>
#include <QObject>

class User : public QObject{
public:
    User() = default;
    User(const QString& userid,const QString& firstName,const QString& lastName,const QString& mail,
        const QString& role,QObject* parent = nullptr);
    User(const User& other);
    QString getuserid()const;
    QString getFirstName()const;
    QString getLastName()const;
    QString getMail()const;
    QString getRole()const;
private:
    QString userid;
    QString firstName;
    QString lastName;
    QString mail;
    QString role;

};

#endif // USER_H
