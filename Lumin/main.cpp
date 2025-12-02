#include <QApplication>

#include "mainwindow.h"
#include "loginform.h"
#include "registerform.h"
#include "verifyform.h"
#include "successform.h"
#include "resetpassform.h"
#include "dashboard.h"
#include "transactions.h"
#include "settings.h"
int main(int argc,char* argv[]){

    QApplication app(argc,argv);
    // MainWindow form;
    // form.show();
    VerifyForm vf("a", "b");
    vf.show();
    app.exec();
}
