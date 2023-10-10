#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>

class UserModel {
public:
    UserModel(int id, const QString &username, bool isBanned);
    int getId() const;
    QString getUsername() const;
    bool isBanned() const;

private:
    int id;
    QString username;
    bool banned;
};

#endif // USERMODEL_H