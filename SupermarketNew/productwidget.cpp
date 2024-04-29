#include "productwidget.h"

ProductWidget::ProductWidget(const QString& productName, const int productPrice, QLabel* productImage, QWidget* parent)
    : QWidget(parent), productName(productName), productPrice(productPrice), productImage(productImage) {

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* nameLabel = new QLabel(productName);
    QString priceString;
    priceString.setNum(productPrice);
    QLabel* priceLabel = new QLabel(priceString);
    QLabel* imageLabel = productImage;
    QPushButton* addToCartButton = new QPushButton("Add to Order");
    connect(addToCartButton, &QPushButton::clicked,this,&ProductWidget::onAddToOrderClicked);
    Quantity = new QSpinBox();
    Quantity->setMinimum(1);
    Quantity->setMaximum(15);
    Quantity->setValue(1);

    layout->addWidget(imageLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(priceLabel);
    layout->addWidget(Quantity);
    layout->addWidget(addToCartButton);
    setLayout(layout);
}

void ProductWidget::onAddToOrderClicked() {
    emit productAdded(productName, productPrice, Quantity->value());
}
