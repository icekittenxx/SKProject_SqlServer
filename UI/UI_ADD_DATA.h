#ifndef UI_ADD_DATA_H
#define UI_ADD_DATA_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QStandardItemModel>
#include <QSqlQuery>

#include "../DB/DB_SQL.h"

namespace Ui {
class UI_ADD_DATA;
}

class UI_ADD_DATA : public QDialog
{
    Q_OBJECT

public:
    explicit UI_ADD_DATA(QWidget *parent = 0);
    ~UI_ADD_DATA();

    void add_table(QString tab_nam, QVector<QString> col_nam, int pri_key_col);

private slots:
    void on_ADD_CONFIRM_clicked();

private:
    Ui::UI_ADD_DATA *ui;

    QStandardItemModel *model;

    QString table_name;
    QVector<QString> column_name;
    int primary_key_column;

    DB_SQL query_sql;
};

#endif // UI_ADD_DATA_H
