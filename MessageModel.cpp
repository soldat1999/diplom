#include "MessageModel.h"

MessageModel::MessageModel(int id, const QString &content, int userId)
    : id(id), content(content), userId(userId) {}

int MessageModel::getId() const {
    return id;
}

QString MessageModel::getContent() const {
    return content;
}

int MessageModel::getUserId() const {
    return userId;
}