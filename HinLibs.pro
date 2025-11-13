QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccountService.cpp \
    accountwindow.cpp \
    Catalogue.cpp \
    catalogueitemui.cpp \
    checkOutService.cpp \
    LoanRepo.cpp \
    checkoutControl.cpp \
    loginui.cpp \
    main.cpp \
    mainwindow.cpp \
    ReturnService.cpp \
    UserRepo.cpp

HEADERS += \
    AccountService.h \
    accountwindow.h \
    Catalogue.h \
    catalogueitemui.h \
    checkOutService.h \
    Loan.h \
    LoanRepo.h \
    checkoutControl.h \
    loginui.h \
    mainwindow.h \
    ObjectDefs.h \
    ReturnService.h \
    timeUtils.h \
    UserDefs.h \
    UserRepo.h

FORMS += \
    accountwindow.ui \
    catalogueitemui.ui \
    loginui.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
