#include "UI_LOGIN.h"
#include "ui_UI_LOGIN.h"

#include "../LOGIC/LOGIC_USER.h"

UI_LOGIN::UI_LOGIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UI_LOGIN)
{
    ui->setupUi(this);
    ui->EDIT_PASSWORD->setEchoMode(QLineEdit::Password);
}

UI_LOGIN::~UI_LOGIN()
{
    delete ui;
}

void UI_LOGIN::on_BUTTON_LOGIN_clicked()
{
    QString usr, pwd;
    usr = ui->EDIT_USERNAME->text();
    pwd = ui->EDIT_PASSWORD->text();
    qDebug() << usr << " " << pwd << endl;

    LOGIC_USER user_login;
    bool flag = user_login.USER_EXIST(usr, pwd);
    if(flag){
        accept();
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("Username or Password ERROR!"), QMessageBox::Yes);
    }

    ui->EDIT_USERNAME->clear();
    ui->EDIT_PASSWORD->clear();
    ui->EDIT_USERNAME->setFocus();
}

void UI_LOGIN::on_BUTTON_EXIT_clicked()
{
    close();
}
