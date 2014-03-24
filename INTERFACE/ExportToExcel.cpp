#include "ExportToExcel.h"

ExportToExcel::ExportToExcel()
{
}

ExportToExcel::ExportToExcel(QString file_name,  QSqlQuery query_result, QString table_name, QVector<QString> column_name)
{
    if(file_name.isEmpty())
    {
        qDebug() << "fileName is empty";
    }
    QString sheet_name = table_name;

    qDebug() << "fileName" << file_name;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "excelexport");
    if(!db.isValid())
    {
        qDebug() << "export2Excel failed: QODBC not supported.";
    }

    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(file_name).arg(file_name);
    db.setDatabaseName(dsn);

    if(!db.open())
    {
        qDebug() << "export2Excel failed: Create Excel file failed by DRIVER={Microsoft Excel Driver (*.xls)}.";
        //QSqlDatabase::removeDatabase("excelexport");
    }

    QSqlQuery query(db);
    QString  sql_exec = QString("DROP TABLE %1 ").arg(sheet_name);
    query.exec(sql_exec);

    sql_exec = QString("CREATE TABLE %1 (").arg(sheet_name);
    for(int i = 0; i < column_name.size(); i ++)
    {
        if(i)
            sql_exec += ", ";
        sql_exec += column_name[i];
        sql_exec += " char(128) ";
    }

    sql_exec += ")";
    //qDebug()<<"sql_exec"<<sql_exec;
    query.prepare(sql_exec);

    if(!query.exec())
    {
        qDebug() << "export2Excel failed: Create Excel sheet failed.";
        db.close();
        //QSqlDatabase::removeDatabase("excelexport");
    }

    //qDebug() << "here 1";

    while(query_result.next())
    {
        sql_exec = QString("INSERT INTO %1 (").arg(sheet_name);
        QVector<QString> variable;
        for(int i = 0; i < column_name.size(); i ++)
        {
            if(i)
                sql_exec += ", ";
            sql_exec += column_name[i];
            QString temp_string = ":variable";
            temp_string += QString::number(i, 10);
            variable.push_back(temp_string);
        }
        sql_exec += ")";
        sql_exec += " VALUES (";
        for(int i = 0; i < column_name.size(); i ++)
        {
            if(i)
                sql_exec += ", ";
            sql_exec += variable[i];
        }
        sql_exec += ")";
        qDebug() << sql_exec;
        query.prepare(sql_exec);

        for(int i = 0; i < column_name.size(); i ++)
        {
            //qDebug() << variable[i] << query_result.value(i).toString();
            query.bindValue(variable[i], query_result.value(i).toString());
        }

        query.exec();
    }
}
