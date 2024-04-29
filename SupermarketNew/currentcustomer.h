#ifndef CURRENTCUSTOMER_H
#define CURRENTCUSTOMER_H
#include <QWidget>

class CurrentCustomer {
public:
    static CurrentCustomer& instance();

    const QString& userName() const { return m_userName; }
    void setUserName(const QString& userName) { m_userName = userName; }

private:
    CurrentCustomer(); // Private constructor to enforce singleton pattern

    QString m_userName;

    static CurrentCustomer* m_instance;
};

#endif // CURRENTCUSTOMER_H
