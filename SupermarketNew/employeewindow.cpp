#include "employeewindow.h"
#include "ui_employeewindow.h"

EmployeeWindow::EmployeeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeWindow)
{
    ui->setupUi(this);
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}

void EmployeeWindow::on_AddProductbtn_clicked()
{
    AddProduct* ap = new AddProduct();
    this->hide();
    ap->show();

}


void EmployeeWindow::on_AddDiscountbtn_clicked()
{
    AddDiscount* ad = new AddDiscount();
    this->hide();
    ad->show();
}


void EmployeeWindow::on_AddSupplierbtn_clicked()
{
    AddSupplier* as = new AddSupplier();
    this->hide();
    as->show();
}


void EmployeeWindow::on_Backbtn_clicked()
{
    login* l = new login();
    this->hide();
    l->show();
}


void EmployeeWindow::on_ViewOrderbtn_clicked()
{
    ViewCustOrder* vco =  new ViewCustOrder();
    this->hide();
    vco->show();
}

