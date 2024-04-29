#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QMainWindow>
#include <employeewindow.h>
#include <globaldatabase.h>
#include <qfiledialog.h>

namespace Ui {
class AddProduct;
}

class AddProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:
    void on_Addproduct_btn_clicked();

    void on_back_btn_clicked();

    void on_Browse_btn_clicked();

private:
    Ui::AddProduct *ui;
    QSqlDatabase db = getGlobalDatabase();
    QString filePath;
    QString newfilePath;
    QString stringWithQuotations;
};

#endif // ADDPRODUCT_H
