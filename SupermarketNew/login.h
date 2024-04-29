#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <Qpixmap>
#include <QFile>
#include <QDebug>
#include <employeewindow.h>
#include <currentcustomer.h>
#include <registerwindow.h>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_logindoneBTN_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
