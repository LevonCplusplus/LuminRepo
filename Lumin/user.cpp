#include "user.h"

User::User(const QString& userid,const QString& firstName,
           const QString& lastName,const QString& mail,
           const QString& role,QObject* parent)
    :QObject(parent),userid(userid),firstName(firstName),lastName(lastName),mail(mail),role(role){}

User::User(const User& other):User(other.userid,other.firstName,other.lastName,other.mail,other.role,other.parent()){}

QString User::getuserid()const{
    return userid;
}
QString User::getFirstName()const{
    return firstName;
}
QString User::getLastName()const{
    return lastName;
}
QString User::getMail()const{
    return mail;
}
QString User::getRole()const{
    return role;
}
