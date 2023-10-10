#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ~MainWindow();

private:
    void banSelectedUser();
    QTableView *usersView;
    QTableView *messagesView;
    QPushButton *banButton;
    QSqlTableModel *usersModel;
    QSqlTableModel *messagesModel;
};

#endif // MAINWINDOW_H