#include "globaldatabase.h"


QSqlDatabase globalDatabase;
void initializeGlobalDatabase(){
    globalDatabase = QSqlDatabase::addDatabase("QODBC");
    globalDatabase.setDatabaseName("SQLODBC");
    if (!globalDatabase.open()) {
        qDebug() << "Error: Failed to connect to database:" << globalDatabase.lastError().text();
        // Handle error
    }
    else {
        qDebug() << "Database Connected" ;
    }
}

void closeAllConnections() {
    // Get a list of all database connections
    QStringList connectionNames = QSqlDatabase::connectionNames();

    // Iterate through the list and close each connection
    foreach (const QString &connectionName, connectionNames) {
        QSqlDatabase::database(connectionName, false).close();
        QSqlDatabase::removeDatabase(connectionName);
    }
}

QSqlDatabase getGlobalDatabase()
{
    return globalDatabase;
}

void CloseGlobalDatabase (){
    globalDatabase.close();
}

// void setUser(QString username){
//     user = username;
// }

// QString getUser(){
//     return user;
// }
