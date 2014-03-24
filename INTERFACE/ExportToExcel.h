#ifndef EXPORTTOEXCEL_H
#define EXPORTTOEXCEL_H

#include <QString>
#include <QVector>
#include <Qtsql/QSqlQuery>
#include <QDebug>

class ExportToExcel
{
public:
    ExportToExcel();
    ExportToExcel(QString file_name,  QSqlQuery query_result, QString table_name, QVector<QString> column_name);
};

#endif // EXPORTTOEXCEL_H
