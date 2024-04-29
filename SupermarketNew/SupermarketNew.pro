QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addiscount.cpp \
    addproduct.cpp \
    addsupplier.cpp \
    currentcustomer.cpp \
    customerwindow.cpp \
    employeewindow.cpp \
    globaldatabase.cpp \
    login.cpp \
    main.cpp \
    entry.cpp \
    productwidget.cpp \
    registerwindow.cpp \
    viewcustorder.cpp

HEADERS += \
    addiscount.h \
    addproduct.h \
    addsupplier.h \
    currentcustomer.h \
    customerwindow.h \
    employeewindow.h \
    entry.h \
    globaldatabase.h \
    login.h \
    productwidget.h \
    registerwindow.h \
    viewcustorder.h

FORMS += \
    addiscount.ui \
    addproduct.ui \
    addsupplier.ui \
    customerwindow.ui \
    employeewindow.ui \
    entry.ui \
    login.ui \
    registerwindow.ui \
    viewcustorder.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
