#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <Qpixmap>
#include <QFile>
#include <QDebug>
#include <QtWidgets>
#include <currentcustomer.h>
#include <login.h>

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerWindow(QWidget *parent = nullptr);
    void AddProdToOrder(QString ProdName , int ProdPrice , int Quantity);
    ~CustomerWindow();


private slots:
    void on_ViewOrder_BTN_clicked();

    void on_Backbtn_clicked();

private:
    Ui::CustomerWindow *ui;
    QList<QString> Strings;
    QList<int> Prices;
    QList<int> Quantities;
};

#endif // CUSTOMERWINDOW_H
