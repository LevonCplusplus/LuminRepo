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
#include "user.h"

int main(int argc,char* argv[]){

    QApplication app(argc,argv);
    // MainWindow form;
    // User user;
    // Dashboard dash(user);
    //dash.show();
    VerifyForm vf("a","b");
    vf.show();
    app.exec();
}
//123456
