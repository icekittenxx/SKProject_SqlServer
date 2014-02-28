#include "UI_MainWindow.h"
#include "ui_UI_MainWindow.h"

UI_MainWindow::UI_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UI_MainWindow)
{
    ui->setupUi(this);
}

UI_MainWindow::~UI_MainWindow()
{
    delete ui;
}

void UI_MainWindow::on_SELECT_WELL_clicked()
{
    ui_well.show();
}
