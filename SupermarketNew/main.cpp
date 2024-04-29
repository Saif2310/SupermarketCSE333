#include "entry.h"
#include "globaldatabase.h"
#include "addproduct.h"
#include "addsupplier.h"
#include "customerwindow.h"
#include "viewcustorder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    closeAllConnections();
    initializeGlobalDatabase();
    Entry w;
    w.show();
    return a.exec();
}
