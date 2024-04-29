#ifndef GLOBALDATABASE_H
#define GLOBALDATABASE_H

#include <Qtsql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <Qpixmap>
#include <QFile>
#include <QDebug>

extern QSqlDatabase globalDatabase;
extern void initializeGlobalDatabase();

extern QSqlDatabase getGlobalDatabase();

// extern void setUser(QString username);
// extern QString getUser();


extern void CloseGlobalDatabase ();
extern void closeAllConnections();

// extern QString user;



#endif // GLOBALDATABASE_H
