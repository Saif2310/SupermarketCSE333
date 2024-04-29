#include "customerwindow.h"
#include "ui_customerwindow.h"
#include "globaldatabase.h"
#include "productwidget.h"



CustomerWindow::CustomerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = getGlobalDatabase();
    QSqlQuery queryproduct(db);
    QVector<ProductWidget*> productWidgets;
    queryproduct.prepare("SELECT [ProductName],[ProductPrice],[ProductImage] FROM [Supermarket].[dbo].[Product]");
    if(queryproduct.exec()){
        while(queryproduct.next()){
            QString productName = queryproduct.value("ProductName").toString();
            int productPrice = queryproduct.value("ProductPrice").toInt();
            QString productImagePath = queryproduct.value("ProductImage").toString();
            QPixmap image(productImagePath);
            image = image.scaled(150, 150, Qt::KeepAspectRatio);
            QLabel *label = new QLabel(this);
            label->setPixmap(image);


            ProductWidget* productWidget = new ProductWidget(productName, productPrice, label,nullptr);
            connect(productWidget,&ProductWidget::productAdded,this,&CustomerWindow::AddProdToOrder);
            productWidgets.append(productWidget);
        }
    }
    else{
        qDebug() << "Error: Failed to execute query:" << queryproduct.lastError().text();
    }

    QWidget* container = new QWidget;
    QGridLayout* layout = new QGridLayout(container);
    int row = 0;
    int col = 0;
    foreach(ProductWidget* widget, productWidgets) {
        layout->addWidget(widget, row, col);
        col++;
        if (col == 4) {
            col = 0;
            row++;
        }
    }
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);
    container->setLayout(layout);

    ui->ProductArea->setWidgetResizable(true);
    ui->ProductArea->setWidget(container);
}

CustomerWindow::~CustomerWindow()
{
    delete ui;
}

void CustomerWindow::on_ViewOrder_BTN_clicked()
{
    ui->ViewOrder_BTN->setStyleSheet("background-color : green");
    QSqlDatabase db = getGlobalDatabase();
    int OrderSum = 0;
    for(int i=0 ; i<Prices.size() ; i++){
        OrderSum += (Prices.at(i)*Quantities.at(i));
    }
    QString name = CurrentCustomer::instance().userName();
    QString ssn;
    int maxid;
    QSqlQuery getmaxorderid(db);
    getmaxorderid.prepare("SELECT max(OrderID) AS OrderID FROM [Supermarket].[dbo].[Orders]");
    if(getmaxorderid.exec()){
        while(getmaxorderid.next()){
            maxid = (getmaxorderid.value("OrderID").toInt())+1;
        }
    }
    QSqlQuery getCSSN(db);
    getCSSN.prepare("SELECT SSN FROM [Supermarket].[dbo].[Customer] WHERE CustomerName = :CustName;");
    getCSSN.bindValue(":CustName",name);
    if(getCSSN.exec()){
        while(getCSSN.next()){
            ssn = getCSSN.value("SSN").toString();
        }
    }
    QSqlQuery AddOrder(db);
    AddOrder.prepare("EXEC [Supermarket].[dbo].[InsertOrder] @OID = :OID,@CSSN = :CSSN,@IP = :IP");
    AddOrder.bindValue(":OID",maxid);
    AddOrder.bindValue(":CSSN",ssn);
    AddOrder.bindValue(":IP",OrderSum);
    int totalprice = OrderSum*1.14;
    if(AddOrder.exec()){
    }

    for(int i=0 ; i<Strings.size() ; i++){
        QString productname = Strings.at(i);
        int prodid;
        QSqlQuery getprodID(db);
        getprodID.prepare("SELECT ProductID from [Supermarket].[dbo].[Product] WHERE ProductName = :ProdName");
        getprodID.bindValue(":ProdName",productname);
        if(getprodID.exec()){
            while(getprodID.next()){
                prodid = getprodID.value("ProductID").toInt();
            }
        }
        int quantity = Quantities.at(i);
        QSqlQuery AddtoConsistsOf(db);
        AddtoConsistsOf.prepare("INSERT INTO [Supermarket].[dbo].[ConsistsOf] (OrderID,ProductID,Quantity) VALUES (:OrderID,:ProductID , :Quantity) ");
        AddtoConsistsOf.bindValue(":OrderID",maxid);
        AddtoConsistsOf.bindValue(":ProductID",prodid);
        AddtoConsistsOf.bindValue(":Quantity",quantity);
        if(AddtoConsistsOf.exec()){
        }
    }
}

void CustomerWindow::AddProdToOrder(QString ProdName , int ProdPrice , int Quantity){
    Strings.append(ProdName);
    Prices.append(ProdPrice);
    Quantities.append(Quantity);
    qDebug()<<Prices.at(0);
}



void CustomerWindow::on_Backbtn_clicked()
{
    login* l = new login();
    this->hide();
    l->show();
}

