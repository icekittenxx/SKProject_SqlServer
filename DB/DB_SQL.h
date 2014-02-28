#ifndef DB_SQL_H
#define DB_SQL_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QDebug>
#include <QVector>

class DB_SQL
{
public:
    DB_SQL();

    QSqlQuery SELECT_EXCUTE(QString select_column, QString table_name);
    QSqlQuery SELECT_CONDITION_EXCUTE(QString select_column, QString table_name, QVector<QString> col_name, QVector<QString> value);
    QSqlQuery SELECT_CONDITION_EXCUTE_SPECIAL_PAGE(QString select_column, QString table_name, QVector<QString> col_name, QVector<QString> value, QString pri_key_nam, int page_number, int page_size);
    bool UPDATE_CONDITION_EXCUTE(QVector<QString> set_column, QVector<QString> set_value, QString table_name, QVector<QString> con_col, QVector<QString> col_val);
    bool DELETE_CONDITION_EXCUTE(QString table_name, QVector<QString> con_col, QVector<QString> col_val);
    bool INSERT_CONDITION_EXCUTE(QVector<QString> ins_column, QVector<QString> ins_value, QString table_name);

    QString QSTRING_SELECT_COLUMN(QVector<QString> col_nam);
    QString QSTRING_SELECT_TABLE(QString select_column, QString table_name);
    QString QSTRING_SELECT_ALL_TABLE(QString table_name);
};

#endif // DB_SQL_H
