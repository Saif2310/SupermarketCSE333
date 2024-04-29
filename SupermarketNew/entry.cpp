#include "entry.h"
#include "ui_entry.h"
#include "login.h"
#include "globaldatabase.h"
#include "registerwindow.h"

Entry::Entry(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Entry)
{
    ui->setupUi(this);
    QString testnum;
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery testquery(db);
    testquery.prepare("SELECT TOP (1) * FROM [Supermarket].[dbo].[Discount] WHERE DiscountID = 'Summer24'");
    if(testquery.exec()){
        while(testquery.next()){
            testnum = testquery.value("DiscountID").toString();
        }
    }
    ui->label_login->setText(testnum);
}

Entry::~Entry()
{
    delete ui;
}

void Entry::on_LoginBTN_clicked()
{
    login* l = new login();
    this->hide();
    l->show();
}


void Entry::on_RegisterBTN_clicked()
{
    RegisterWindow* rw = new RegisterWindow();
    this->hide();
    rw->show();
}

