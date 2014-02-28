#ifndef SQLQUERYMODEL_RW_H
#define SQLQUERYMODEL_RW_H

#include <QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QVector>

#include "../DB/DB_SQL.h"

class SqlQueryModel_RW : public QSqlQueryModel
{
public:
    SqlQueryModel_RW();
    SqlQueryModel_RW::SqlQueryModel_RW(QString tab_nam, QVector<QString> col_nam, int pri_key_col, int p_size);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void query_one_column(QString col_nam, QString col_val);
    void delete_one_column(QString pri_key_val);
    void refresh();

    int get_row_count();
    int get_page_number();
    void set_page_number(int p_n);

private:
    QString table_name;
    QVector<QString> column_name;
    int primary_key_column;
    DB_SQL query_sql;

    QVector<QString> sel_con_col_nam, sel_con_col_val;
    int page_size;
    int page_number;
    int first_page_number;
    int row_count;

    bool setSqlServerData(QString primary_key_name, QString primary_key_value, QString column_name, QString value);
};

#endif // SQLQUERYMODEL_RW_H
