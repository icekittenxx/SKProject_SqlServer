#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>

#include <QVector>
#include <QString>

#include "UI_WELL.h"

namespace Ui {
class UI_MainWindow;
}

class UI_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UI_MainWindow(QWidget *parent = 0);
    ~UI_MainWindow();

private slots:
    void on_SELECT_WELL_clicked();

private:
    Ui::UI_MainWindow *ui;

    UI_WELL ui_well;
};

#endif // UI_MAINWINDOW_H
