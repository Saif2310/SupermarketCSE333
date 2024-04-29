#include "addsupplier.h"
#include "ui_addsupplier.h"

AddSupplier::AddSupplier(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddSupplier)
{
    ui->setupUi(this);
}

AddSupplier::~AddSupplier()
{
    delete ui;
}

void AddSupplier::on_back_btn_clicked()
{
    EmployeeWindow* ew = new EmployeeWindow();
    this->hide();
    ew->show();
}


void AddSupplier::on_Add_btn_clicked()
{
    int newid =0;
    QSqlDatabase db = getGlobalDatabase();
    QString query = "SELECT MAX(SupplierID) + 1 AS NewSupplierID FROM [Supermarket].[dbo].[Supplier]";
    QSqlQuery getnewSID(db);
    getnewSID.prepare(query);

    if (getnewSID.exec()) {
        if (getnewSID.next()) {
            newid = getnewSID.value("NewSupplierID").toInt();
            qDebug() << newid;
        } else {
            // Handle the case where no data is returned (e.g., empty table)
            qWarning() << "No supplier found to generate new ID";
        }
    } else {
        // Handle execution errors
        qWarning() << "Error executing query:" << getnewSID.lastError().text();
    }
    QString SupplierName = ui->Name_textedit->toPlainText();
    QSqlQuery AddSupp(db);
    AddSupp.prepare("INSERT INTO [Supermarket].[dbo].[Supplier] (SupplierID, SupplierName) VALUES (:SupplierID , :SupplierName);");
    AddSupp.bindValue(":SupplierID" , newid);
    AddSupp.bindValue(":SupplierName" , SupplierName);
    if (AddSupp.exec()){
        qDebug()<< "Query Successful";
    }
}

