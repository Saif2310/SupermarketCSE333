#ifndef ADDSUPPLIER_H
#define ADDSUPPLIER_H

#include <QMainWindow>
#include <employeewindow.h>

namespace Ui {
class AddSupplier;
}

class AddSupplier : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSupplier(QWidget *parent = nullptr);
    ~AddSupplier();

private slots:
    void on_back_btn_clicked();

    void on_Add_btn_clicked();

private:
    Ui::AddSupplier *ui;
};

#endif // ADDSUPPLIER_H
