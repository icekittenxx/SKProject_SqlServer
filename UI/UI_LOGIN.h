#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class UI_LOGIN;
}

class UI_LOGIN : public QDialog
{
    Q_OBJECT

public:
    explicit UI_LOGIN(QWidget *parent = 0);
    ~UI_LOGIN();

private slots:
    void on_BUTTON_LOGIN_clicked();

    void on_BUTTON_EXIT_clicked();

private:
    Ui::UI_LOGIN *ui;
};

#endif // UI_LOGIN_H
