#include <QApplication>

#include "UI/UI_MainWindow.h"
#include "UI/UI_LOGIN.h"

#include "DB/DB_CONNECT.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DB_CONNECT my_db_connect;
    //my_db_connect.DB_TEST();

    UI_MainWindow w;
    UI_LOGIN login;

    if(login.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }

    return a.exec();
}
