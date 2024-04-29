#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>

class ProductWidget : public QWidget {
    Q_OBJECT
public:
    ProductWidget(const QString& productName, const int productPrice, QLabel* productImage, QWidget* parent = nullptr);

signals:
    void productAdded (QString productName, int productPrice, int quantity);
private:
    QString productName;
    int productPrice;
    QLabel* productImage;
    QSpinBox* Quantity;

private slots:
    void onAddToOrderClicked();
};

#endif // PRODUCTWIDGET_H
