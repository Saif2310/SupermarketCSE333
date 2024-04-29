#ifndef VIEWCUSTORDER_H
#define VIEWCUSTORDER_H

#include <QMainWindow>
#include <employeewindow.h>

namespace Ui {
class ViewCustOrder;
}

class ViewCustOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewCustOrder(QWidget *parent = nullptr);
    ~ViewCustOrder();

private slots:
    void on_back_btn_clicked();

    void on_Enter_SSN_btn_clicked();

    void on_Select_Order_btn_clicked();

private:
    Ui::ViewCustOrder *ui;
};

#endif // VIEWCUSTORDER_H
