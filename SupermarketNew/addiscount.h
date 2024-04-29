#ifndef ADDISCOUNT_H
#define ADDISCOUNT_H

#include <QMainWindow>
#include <employeewindow.h>

namespace Ui {
class AddDiscount;
}

class AddDiscount : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDiscount(QWidget *parent = nullptr);
    ~AddDiscount();

private slots:
    void on_Backbtn_clicked();

    void on_Addbtn_clicked();

private:
    Ui::AddDiscount *ui;
};

#endif // ADDISCOUNT_H
