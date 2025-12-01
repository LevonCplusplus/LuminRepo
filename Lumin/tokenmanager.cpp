#include "tokenmanager.h"

TokenManager::TokenManager(QObject* parent)
    :QObject(parent)
{}

void TokenManager::updateAccessToken(const QString& token){
    accessToken = token;
}
void TokenManager::updateRefreshToken(const QString& token){
    refreshToken = token;
}
QString TokenManager::getAccessToken()const{
    return accessToken;
}
QString TokenManager::getRefreshToken()const{
    return refreshToken;
}
