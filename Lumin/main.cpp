#include <QApplication>

#include "loginform.h"
#include "registerform.h"
#include "verifyform.h"
#include "successform.h"
#include "resetpassform.h"
#include "dashboardleft.h"

int main(int argc,char* argv[]){

    QApplication app(argc,argv);

    DashboardLeft form;
    form.show();
    app.exec();
}
