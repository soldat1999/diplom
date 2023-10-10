#include "MainWindow.h"
#include "DatabaseManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Create UI Components
    usersView = new QTableView(this);
    messagesView = new QTableView(this);
    banButton = new QPushButton("Ban User", this);

    // Create Layouts
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usersView);
    layout->addWidget(messagesView);
    layout->addWidget(banButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Create Model for Users and Set to usersView
    DatabaseManager dbManager;
    dbManager.connect("your_db_name"); // Make sure to change to your database name

    usersModel = new QSqlTableModel(this, dbManager.db);
    usersModel->setTable("users");
    usersModel->select();
    usersView->setModel(usersModel);

    // Create Model for Messages and Set to       messagesView
    messagesModel = new QSqlTableModel(this,     dbManager.db);
    messagesModel->setTable("messages");
    messagesModel->select();
    messagesView->setModel(messagesModel);

    // Connect banButton to the slot
    connect(banButton, SIGNAL(clicked()), this, SLOT(banSelectedUser()));
}

MainWindow::~MainWindow() {}

void MainWindow::banSelectedUser() {
    int row = usersView->currentIndex().row();
    int userId = usersModel->record(row).value("id").toInt();

    DatabaseManager dbManager;
    dbManager.connect("your_db_name"); // Make sure to change to your database name

    if (dbManager.banUser(userId)) {
        QMessageBox::information(this, "Success", "User banned successfully!");
        usersModel->select();  // Refresh the view
    } else {
        QMessageBox::warning(this, "Error", "Failed to ban the user!");
    }
}