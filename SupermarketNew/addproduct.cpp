#include "addproduct.h"
#include "ui_addproduct.h"

AddProduct::AddProduct(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    ui->SID_comboBox->addItem("None");
    ui->DID_comboBox->addItem("None");
    QSqlQuery populateSIDquery(db);
    populateSIDquery.prepare("SELECT SupplierName FROM [Supermarket].[dbo].[Supplier]");
        if(populateSIDquery.exec()){
            while(populateSIDquery.next()){
                QString SuppName = populateSIDquery.value("SupplierName").toString();
                ui->SID_comboBox->addItem(SuppName);
            }
    }
    QSqlQuery populateDIDquery(db);
    populateDIDquery.prepare("SELECT DiscountName FROM [Supermarket].[dbo].[Discount]");
    if(populateDIDquery.exec()){
        while(populateDIDquery.next()){
            QString DisName = populateDIDquery.value("DiscountName").toString();
            ui->DID_comboBox->addItem(DisName);
        }
    }
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_Addproduct_btn_clicked()
{
    QSqlQuery getPIDQuery(db);
    db.close();
    if(db.open()){

        getPIDQuery.prepare("SELECT ProductID FROM [Supermarket].[dbo].[Product] WHERE ProductID = (SELECT MAX(ProductID) FROM [Supermarket].[dbo].[Product]);");
        if(!getPIDQuery.exec()){
            qDebug() << "Error executing query:" << getPIDQuery.lastError().text();
        }
        int ProductID;
        if(getPIDQuery.next()){
            ProductID = (getPIDQuery.value("ProductID").toInt())+1;
            qDebug() << "PID";
        }

        QString ProdName = ui->Product_name_textEdit->toPlainText();
        int ProdPrice = ui->Price_spinBox->value();
        QString ProdType = ui->Type_textedit->toPlainText();
        QString SupplierName = ui->SID_comboBox->currentText();
        QString SupplierID;

        QSqlQuery getSIDQuery(db);
        getSIDQuery.prepare("SELECT SupplierID FROM [Supermarket].[dbo].[Supplier] WHERE SupplierName = :SuppName ");
        getSIDQuery.bindValue(":SuppName" , SupplierName);
        if(!getSIDQuery.exec()){
            qDebug() << "Error executing query:" << getSIDQuery.lastError().text();
        }
        if(getSIDQuery.next()){
            SupplierID = getSIDQuery.value("SupplierID").toString();
            qDebug() << "SID";
        }

        QString DiscountName = ui->DID_comboBox->currentText();
        QString DiscountID;

        QSqlQuery getDIDQuery(db);
        getDIDQuery.prepare("SELECT DiscountID FROM [Supermarket].[dbo].[Discount] WHERE DiscountName = :DisName ");
        getDIDQuery.bindValue(":DisName" , DiscountName);
        if(!getDIDQuery.exec()){
            qDebug() << "Error executing query:" << getDIDQuery.lastError().text();
        }
        if(getDIDQuery.next()){
            DiscountID = getDIDQuery.value("DiscountID").toString();
            qDebug() << "DID";
        }

        int DiscPercentage = ui->PercentageSpinBox->value();
        QSqlQuery AddProdQuery(db);
        AddProdQuery.clear();


        AddProdQuery.prepare("EXEC [Supermarket].[dbo].[InsertProduct]  @ProductID =:ProductID, @ProductName =:ProductName, @ProductPrice =:ProductPrice, @ProductImagePath =:ProductImage, @ProductType =:ProductType, @SupplierID =:SupplierID, @DiscountID =:DiscountID, @DiscountPercentage =:DiscountPercentage;");
        AddProdQuery.bindValue(":ProductID", ProductID);
        AddProdQuery.bindValue(":ProductName", ProdName); // Ensure string values are quoted
        AddProdQuery.bindValue(":ProductPrice", ProdPrice);
        AddProdQuery.bindValue(":ProductImage", filePath); // Ensure string values are quoted
        AddProdQuery.bindValue(":ProductType", ProdType); // Ensure string values are quoted
        AddProdQuery.bindValue(":SupplierID", SupplierID);
        AddProdQuery.bindValue(":DiscountID", DiscountID); // Ensure string values are quoted
        AddProdQuery.bindValue(":DiscountPercentage", DiscPercentage);
        if(AddProdQuery.exec()){
            qDebug()<< "query successful";
            while(AddProdQuery.next()){
            }
        }
    }
    else{
        qDebug() << "not opened";
    }
}


void AddProduct::on_back_btn_clicked()
{
    EmployeeWindow* ew = new EmployeeWindow();
    this->hide();
    ew->show();
}


void AddProduct::on_Browse_btn_clicked()
{
    filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", "", "Images (*.png *.jpg *.jpeg)");
    stringWithQuotations = "'" + filePath  + "'";
}

