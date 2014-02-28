#ifndef LOGIC_WELL_H
#define LOGIC_WELL_H

#include <QString>
#include <QVector>

class LOGIC_WELL
{
public:
    LOGIC_WELL();

    QVector<QString> column_name;
    int primary_key_column;
    QString table_name;
};

#endif // LOGIC_WELL_H
