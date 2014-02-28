#include "DB_SQL.h"

DB_SQL::DB_SQL()
{
}

QSqlQuery DB_SQL::SELECT_EXCUTE(QString select_column, QString table_name)
{
    QSqlQuery query;
    QString select_sql = QSTRING_SELECT_TABLE(select_column, table_name);
    query.exec(select_sql);
    return query;
}

QSqlQuery DB_SQL::SELECT_CONDITION_EXCUTE(QString select_column, QString table_name, QVector<QString> col_name, QVector<QString> value)
{
    QSqlQuery query;
    QString select_sql = "";

    select_sql += "select ";
    select_sql += select_column;
    select_sql += " from ";
    select_sql += table_name;

    int size = col_name.size();
    if(size > 0)
    {
        select_sql += " where ";

        for(int i = 0; i < size; i ++)
        {
            if(i > 0)
            {
                select_sql += " and ";
            }
            select_sql += col_name[i];
            select_sql += " = ?";
        }

        query.prepare(select_sql);
        for(int i = 0; i < size; i ++)
        {
            query.addBindValue(value[i]);
        }
        query.exec();
    }
    else
    {
        query.exec(select_sql);
    }
    return query;
}

QSqlQuery DB_SQL::SELECT_CONDITION_EXCUTE_SPECIAL_PAGE(QString select_column, QString table_name, QVector<QString> col_name, QVector<QString> value, QString pri_key_nam, int page_number, int page_size)
{
    QSqlQuery query;
    QString select_sql = "";
    if(page_number == 0)
    {
        select_sql += "select top ";
        select_sql += QString::number(page_size, 10);
        select_sql += " ";
        select_sql += select_column;
        select_sql += " from ";
        select_sql += table_name;

        int size = col_name.size();
        if(size > 0)
        {
            select_sql += " where ";

            for(int i = 0; i < size; i ++)
            {
                if(i > 0)
                {
                    select_sql += " and ";
                }
                select_sql += col_name[i];
                select_sql += " = ?";
            }

            qDebug() << select_sql;

            query.prepare(select_sql);
            for(int i = 0; i < size; i ++)
            {
                query.addBindValue(value[i]);
            }
            query.exec();
        }
        else
        {
            query.exec(select_sql);
        }
    }
    else
    {
        select_sql += "select top ";
        select_sql += QString::number(page_size, 10);
        select_sql += " ";
        select_sql += select_column;
        select_sql += " from ";
        select_sql += table_name;

        select_sql += " where ";
        select_sql += pri_key_nam;
        select_sql += " not in ( select top ";
        select_sql += QString::number(page_size * page_number, 10);
        select_sql += " ";
        select_sql += pri_key_nam;
        select_sql += " from ";
        select_sql += table_name;

        int size = col_name.size();
        if(size > 0)
        {
            select_sql += " where ";
            for(int i = 0; i < size; i ++)
            {
                if(i > 0)
                {
                    select_sql += " and ";
                }
                select_sql += col_name[i];
                select_sql += " = ?";
            }
            select_sql += ") and ";
            for(int i = 0; i < size; i ++)
            {
                if(i > 0)
                {
                    select_sql += " and ";
                }
                select_sql += col_name[i];
                select_sql += " = ?";
            }
            qDebug() << select_sql;

            query.prepare(select_sql);
            for(int i = 0; i < size; i ++)
            {
                query.addBindValue(value[i]);
            }
            for(int i = 0; i < size; i ++)
            {
                query.addBindValue(value[i]);
            }

            query.exec();
        }
        else
        {
            select_sql += ")";

            qDebug() << select_sql;
            query.exec(select_sql);
        }
    }
    return query;
}

bool DB_SQL::UPDATE_CONDITION_EXCUTE(QVector<QString> set_column, QVector<QString> set_value, QString table_name, QVector<QString> con_col, QVector<QString> col_val)
{
    QString select_sql = "";
    select_sql += "update ";
    select_sql += table_name;
    select_sql += " set ";
    int set_size = set_column.size();
    for(int i = 0; i < set_size; i ++)
    {
        if(i > 0)
        {
            select_sql += ", ";
        }
        select_sql += set_column[i];
        select_sql += " = ?";
    }
    select_sql += " where ";
    int con_size = con_col.size();
    for(int i = 0; i < con_size; i ++)
    {
        if(i > 0)
        {
            select_sql += " and ";
        }
        select_sql += con_col[i];
        select_sql += " = ?";
    }
    qDebug() << select_sql;

    QSqlQuery query;
    query.prepare(select_sql);
    for(int i = 0; i < set_size; i ++)
    {
        query.addBindValue(set_value[i]);
        qDebug() << set_value[i];
    }
    for(int i = 0; i < con_size; i ++)
    {
        query.addBindValue(col_val[i]);
        qDebug() << col_val[i];
    }
    return query.exec();
}

bool DB_SQL::DELETE_CONDITION_EXCUTE(QString table_name, QVector<QString> con_col, QVector<QString> col_val)
{
    QString select_sql = "";
    select_sql += "delete from ";
    select_sql += table_name;
    select_sql += " where ";
    int con_size = con_col.size();
    for(int i = 0; i < con_size; i ++)
    {
        if(i > 0)
        {
            select_sql += " and ";
        }
        select_sql += con_col[i];
        select_sql += " = ?";
    }
    qDebug() << select_sql;

    QSqlQuery query;
    query.prepare(select_sql);
    for(int i = 0; i < con_size; i ++)
    {
        query.addBindValue(col_val[i]);
        qDebug() << col_val[i];
    }
    return query.exec();
}

bool DB_SQL::INSERT_CONDITION_EXCUTE(QVector<QString> ins_column, QVector<QString> ins_value, QString table_name)
{
    QString select_sql = "";
    select_sql += "insert into ";
    select_sql += table_name;
    select_sql += " ( ";
    int ins_size = ins_column.size();
    for(int i = 0; i < ins_size; i ++)
    {
        if(i > 0)
        {
            select_sql += ", ";
        }
        select_sql += ins_column[i];
    }
    select_sql += " ) values ( ";
    for(int i = 0; i < ins_size; i ++)
    {
        if(i > 0)
        {
            select_sql += ", ";
        }
        select_sql += "?";
    }
    select_sql += ")";
    qDebug() << select_sql;

    QSqlQuery query;
    query.prepare(select_sql);

    for(int i = 0; i < ins_size; i ++)
    {
        query.addBindValue(ins_value[i]);
        qDebug() << ins_value[i];
    }
    return query.exec();
}

QString DB_SQL::QSTRING_SELECT_COLUMN(QVector<QString> col_nam)
{
    QString select_column = "";
    int size = col_nam.size();
    for(int i = 0; i < size; i ++)
    {
        if(i > 0)
        {
            select_column += ", ";
        }
        select_column += col_nam[i];
    }
    return select_column;
}

QString DB_SQL::QSTRING_SELECT_TABLE(QString select_column, QString table_name)
{
    QString select_sql = "select " + select_column + " from " + table_name + " ";
    qDebug() << select_sql;
    return select_sql;
}

QString DB_SQL::QSTRING_SELECT_ALL_TABLE(QString table_name)
{
    QString select_sql = "select * from " + table_name;
    return select_sql;
}
