QT += widgets
QT += network
QT += core

CONFIG += c++17

SOURCES += \
    apiclient.cpp \
    dashboard.cpp \
    dashboardcontent.cpp \
    dashboardleft.cpp \
    loadingOverlay.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    multipleedit.cpp \
    passwordhintwidget.cpp \
    registerform.cpp \
    resetpassform.cpp \
    settings.cpp \
    successform.cpp \
    transactions.cpp \
    user.cpp \
    verifyform.cpp

HEADERS += \
    apiclient.h \
    dashboard.h \
    dashboardcontent.h \
    dashboardleft.h \
    loadingOverlay.h \
    loginform.h \
    mainwindow.h \
    multipleedit.h \
    passwordhintwidget.h \
    registerform.h \
    resetpassform.h \
    settings.h \
    successform.h \
    tokenmanager.h \
    transactions.h \
    user.h \
    verifyform.h

RESOURCES += \
    resources.qrc
