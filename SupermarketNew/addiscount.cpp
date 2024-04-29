#include "addiscount.h"
#include "ui_addiscount.h"

AddDiscount::AddDiscount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddDiscount)
{
    ui->setupUi(this);
}

AddDiscount::~AddDiscount()
{
    delete ui;
}

void AddDiscount::on_Backbtn_clicked()
{
    EmployeeWindow* ew = new EmployeeWindow();
    this->hide();
    ew->show();
}


void AddDiscount::on_Addbtn_clicked()
{
    QString DisID = ui->DiscountID_textedit->toPlainText();
    int DisDuration =ui->Duration_spinBox->value();
    QString DisName = ui->DiscountName_textedit->toPlainText();
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery AddDiscQuery(db);
    AddDiscQuery.prepare("INSERT INTO [Supermarket].[dbo].[Discount] (DiscountID , Duration , DiscountName) VALUES (:DisID , :DisDuration, :DisName)");
    AddDiscQuery.bindValue(":DisID",DisID);
    AddDiscQuery.bindValue(":DisDuration",DisDuration);
    AddDiscQuery.bindValue(":DisName",DisName);
    if(AddDiscQuery.exec()){
        while(AddDiscQuery.next()){
            qDebug()<<"query successful";
        }
    }


}

