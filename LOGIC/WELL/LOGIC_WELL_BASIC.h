#ifndef LOGIC_WELL_BASIC_H
#define LOGIC_WELL_BASIC_H

#include <QString>
#include <QVector>

class LOGIC_WELL_BASIC
{
public:
    LOGIC_WELL_BASIC();

    QVector<QString> column_name;
    int primary_key_column;
    QString table_name;
};

#endif // LOGIC_WELL_BASIC_H
