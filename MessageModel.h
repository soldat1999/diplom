#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QString>

class MessageModel {
public:
    MessageModel(int id, const QString &content, int userId);
    int getId() const;
    QString getContent() const;
    int getUserId() const;

private:
    int id;
    QString content;
    int userId;
};

#endif // MESSAGEMODEL_H