#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerbtn_clicked()
{
    QString SSN = ui->SSN_Textedit->toPlainText();
    QString Name = ui->Name_textedit->toPlainText();
    QString Pass = ui->Pass_textedit ->toPlainText();
    QString ConfPass= ui->ConfPass_textedit ->toPlainText();
    if(Pass == ConfPass){
        QSqlDatabase db = getGlobalDatabase();
        QSqlQuery addCustomer(db);
        addCustomer.prepare("INSERT INTO [Supermarket].[dbo].[Customer] (SSN,CustomerName,CustPass) VALUES (:ssn,:custn,:custp)");
        addCustomer.bindValue(":ssn" , SSN);
        addCustomer.bindValue(":custn" , Name);
        addCustomer.bindValue(":custp",Pass);
        if(addCustomer.exec()){
        }
    }
    else{
        ui->ErrorLabel->setStyleSheet("color: red;");
        ui->ErrorLabel->setText("Passwords don't match");
    }
}

void RegisterWindow::on_backbtn_clicked()
{
    login* l = new login();
    this->hide();
    l->show();
}

