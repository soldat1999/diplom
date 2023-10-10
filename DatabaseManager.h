#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();
    bool banUser(int userId);
    QSqlQuery getAllMessages();

    bool connect(const QString &dbname);
    QSqlQuery executeQuery(const QString &query);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H