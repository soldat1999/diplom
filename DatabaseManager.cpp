#include "DatabaseManager.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::connect(const QString &dbname) {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName(dbname);
    return db.open();
}

QSqlQuery DatabaseManager::executeQuery(const QString &query) {
    return QSqlQuery(query, db);
}

bool DatabaseManager::banUser(int userId) {
    QSqlQuery query;
    query.prepare("UPDATE users SET banned = TRUE WHERE id = :userId");
    query.bindValue(":userId", userId);
    return query.exec();
}

QSqlQuery DatabaseManager::getAllMessages() {
    return executeQuery("SELECT * FROM messages");
}
