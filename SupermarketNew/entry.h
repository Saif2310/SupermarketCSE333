#ifndef ENTRY_H
#define ENTRY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Entry;
}
QT_END_NAMESPACE

class Entry : public QMainWindow
{
    Q_OBJECT

public:
    Entry(QWidget *parent = nullptr);
    ~Entry();

private slots:
    void on_LoginBTN_clicked();

    void on_RegisterBTN_clicked();

private:
    Ui::Entry *ui;
};
#endif // ENTRY_H
