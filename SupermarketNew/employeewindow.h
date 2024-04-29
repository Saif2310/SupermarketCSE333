#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QMainWindow>
#include <addiscount.h>
#include <addproduct.h>
#include <addsupplier.h>
#include <viewcustorder.h>
#include <login.h>
#include <viewcustorder.h>

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

private slots:
    void on_AddProductbtn_clicked();

    void on_AddDiscountbtn_clicked();

    void on_AddSupplierbtn_clicked();

    void on_Backbtn_clicked();

    void on_ViewOrderbtn_clicked();

private:
    Ui::EmployeeWindow *ui;
};

#endif // EMPLOYEEWINDOW_H
