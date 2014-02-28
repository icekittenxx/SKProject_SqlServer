#include "SqlQueryModel_RW.h"

SqlQueryModel_RW::SqlQueryModel_RW()
{
}

SqlQueryModel_RW::SqlQueryModel_RW(QString tab_nam, QVector<QString> col_nam, int pri_key_col, int p_size)
{
    table_name = tab_nam;
    column_name = col_nam;
    primary_key_column = pri_key_col;

    page_size = p_size;
    page_number = 0;
    first_page_number = 0;

    QString select_sql = query_sql.QSTRING_SELECT_ALL_TABLE(table_name);
    setQuery(select_sql);

    row_count = rowCount();

    QString select_column = query_sql.QSTRING_SELECT_COLUMN(column_name);
    QSqlQuery query = query_sql.SELECT_CONDITION_EXCUTE_SPECIAL_PAGE(select_column, table_name, sel_con_col_nam, sel_con_col_val, column_name[primary_key_column], first_page_number, page_size);
    setQuery(query);

}

void SqlQueryModel_RW::refresh()
{
    //don't delete
    /*
    QString select_sql = query_sql.QSTRING_SELECT_ALL_TABLE(table_name);
    setQuery(select_sql);
    */

    QString select_column = query_sql.QSTRING_SELECT_COLUMN(column_name);
    QSqlQuery query = query_sql.SELECT_CONDITION_EXCUTE(select_column, table_name, sel_con_col_nam, sel_con_col_val);
    setQuery(query);

    row_count = rowCount();

    QString select_column_again = query_sql.QSTRING_SELECT_COLUMN(column_name);
    QSqlQuery query_again = query_sql.SELECT_CONDITION_EXCUTE_SPECIAL_PAGE(select_column_again, table_name, sel_con_col_nam, sel_con_col_val, column_name[primary_key_column], page_number, page_size);
    setQuery(query_again);
}

Qt::ItemFlags SqlQueryModel_RW::flags(
        const QModelIndex &index)const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    flags |= Qt::ItemIsEditable;
    return flags;
}

bool SqlQueryModel_RW::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    int column_index = index.column();
    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), primary_key_column);
    QString id = data(primaryKeyIndex).toString();
    clear();
    bool set_result;
    set_result = setSqlServerData(column_name[primary_key_column], id, column_name[column_index], value.toString());
    refresh();
    return set_result;
}

bool SqlQueryModel_RW::setSqlServerData(QString primary_key_name, QString primary_key_value, QString column_name, QString value)
{
    QVector<QString> set_col, set_val;
    set_col.push_back(column_name);
    set_val.push_back(value);
    QVector<QString> con_col, con_val;
    con_col.push_back(primary_key_name);
    con_val.push_back(primary_key_value);
    bool flag = query_sql.UPDATE_CONDITION_EXCUTE(set_col, set_val, table_name, con_col, con_val);
    return flag;
}

void SqlQueryModel_RW::query_one_column(QString col_nam, QString col_val)
{
    //don't delete!!
    /*
    QString select_column = query_sql.QSTRING_SELECT_COLUMN(column_name);
    QVector<QString> con_col_nam, con_col_val;
    con_col_nam.push_back(col_nam);
    con_col_val.push_back(col_val);
    QSqlQuery query = query_sql.SELECT_CONDITION_EXCUTE(select_column, table_name, con_col_nam, con_col_val);
    setQuery(query);
    */

    QVector<QString> con_col_nam, con_col_val;
    con_col_nam.push_back(col_nam);
    con_col_val.push_back(col_val);

    sel_con_col_nam = con_col_nam;
    sel_con_col_val = con_col_val;
    refresh();
}

void SqlQueryModel_RW::delete_one_column(QString pri_key_val)
{
    QVector<QString> con_col, con_val;
    con_col.push_back(column_name[primary_key_column]);
    con_val.push_back(pri_key_val);
    query_sql.DELETE_CONDITION_EXCUTE(table_name, con_col, con_val);
    refresh();
}

int SqlQueryModel_RW::get_row_count()
{
    return row_count;
}

int SqlQueryModel_RW::get_page_number()
{
    return page_number;
}

void SqlQueryModel_RW::set_page_number(int p_n)
{
    page_number = p_n;
}
