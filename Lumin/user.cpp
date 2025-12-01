#include "user.h"

User::User(const QString& userid,const QString& firstName,
           const QString& lastName,const QString& mail,
           const QString& role,QObject* parent)
    :QObject(parent),userid(userid),firstName(firstName),lastName(lastName),mail(mail){}
User::User(const User& other){
    userid = other.userid;
    firstName = other.firstName;
    lastName = other.lastName;
    mail = other.mail;
}
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
