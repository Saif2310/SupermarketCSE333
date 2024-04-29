#include "login.h"
#include "ui_login.h"
#include "globaldatabase.h"
#include "customerwindow.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_logindoneBTN_clicked()
{
    bool ValidUser = false;
    std::string userType;
    QString username = ui->textEdit->toPlainText();
    QString userpass = ui->textEdit_2->toPlainText();
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery testquerycust(db);
    testquerycust.prepare("SELECT [CustomerName],[CustPass] FROM [Supermarket].[dbo].[Customer] WHERE CustomerName = :value1 AND CustPass = :value2");
    testquerycust.bindValue(":value1" , QVariant(username));
    testquerycust.bindValue(":value2" , QVariant(userpass));
    QString preparedQuerycust = testquerycust.lastQuery();
    qDebug() << "Prepared Query:" << preparedQuerycust;
    if(testquerycust.exec()){
        if(testquerycust.next()){
            CurrentCustomer::instance().setUserName(username);
            ValidUser = true;
            CustomerWindow* CW = new CustomerWindow();
            this->hide();
            CW->show();
        }
    }
    else{
        qDebug() << "Error: Failed to execute query:" << testquerycust.lastError().text();
    }

    QSqlQuery testqueryemp(db);
    testqueryemp.prepare("SELECT [EmployeeName],[EmpPass] FROM [Supermarket].[dbo].[Employee] WHERE EmployeeName = :value1 AND EmpPass = :value2");
    testqueryemp.bindValue(":value1" , QVariant(username));
    testqueryemp.bindValue(":value2" , QVariant(userpass));
    QString preparedQueryemp = testqueryemp.lastQuery();
    qDebug() << "Prepared Query:" << preparedQueryemp;
    if(testqueryemp.exec()){
        while(testqueryemp.next()){
            ValidUser = true;
            EmployeeWindow* ew = new EmployeeWindow();
            this->hide();
            ew->show();
        }
    }
    else{
        qDebug() << "Error: Failed to execute query:" << testqueryemp.lastError().text();
    }

    if(ValidUser){
        qDebug() << "Valid User";
    }
    else{
        qDebug() << "Invalid User";
    }
}

