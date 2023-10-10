#include UserModel.h

UserModelUserModel(int id, const QString &username, bool isBanned)
     id(id), username(username), banned(isBanned) {}

int UserModelgetId() const {
    return id;
}

QString UserModelgetUsername() const {
    return username;
}

bool UserModelisBanned() const {
    return banned;
}