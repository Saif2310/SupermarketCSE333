#include "viewcustorder.h"
#include "ui_viewcustorder.h"

ViewCustOrder::ViewCustOrder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewCustOrder)
{
    ui->setupUi(this);
}

ViewCustOrder::~ViewCustOrder()
{
    delete ui;
}

void ViewCustOrder::on_back_btn_clicked()
{
    EmployeeWindow* ew = new EmployeeWindow();
    this->hide();
    ew->show();
}


void ViewCustOrder::on_Enter_SSN_btn_clicked()
{
    ui->Orders_listWidget->clear();
    QString ssn = ui->SSN_textedit->toPlainText();
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery GetOrders(db);
    GetOrders.prepare("SELECT [OrderID],[totalpricewithtax] FROM [Supermarket].[dbo].[Orders] WHERE Cust_SSN = :SSN ");
    GetOrders.bindValue(":SSN",ssn);
    if(GetOrders.exec()){
        while(GetOrders.next()){
            QString oid;
            QString TPWT;
            oid = GetOrders.value("OrderID").toString();
            TPWT = GetOrders.value("totalpricewithtax").toString();
            QString orderitem = oid + " , " + "$" + TPWT;
            ui->Orders_listWidget->addItem(orderitem);
        }
    }
}


void ViewCustOrder::on_Select_Order_btn_clicked()
{
    ui->OrderProducts_listWidget->clear();
    QString SelectedOrder = ui->Orders_listWidget->currentItem()->text();
    QStringList splitText = SelectedOrder.split(",");
    QString oid = splitText.first();
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery GetProducts(db);
    GetProducts.prepare("EXEC [Supermarket].[dbo].[GetProducts ] @OID = :OID;");
    GetProducts.bindValue(":OID",oid);
    if(GetProducts.exec()){
        while(GetProducts.next()){
            QString Prodname = GetProducts.value("ProductName").toString();
            QString quantity = GetProducts.value("Quantity").toString();
            QString price = "$" + GetProducts.value("ProductPrice").toString();
            QString proditem = Prodname +" , "+ quantity +" , "+price;
            ui->OrderProducts_listWidget->addItem(proditem);
        }
    }
}

