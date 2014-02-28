#ifndef LOGIC_USER_H
#define LOGIC_USER_H

#include <QString>
#include <QVector>
#include <QString>

class LOGIC_USER
{
public:
    LOGIC_USER();

    bool USER_EXIST(QString usr, QString pwd);

    QVector<QString> column_name;
    //QVector<QString> column_type;
    int primary_key_column;

//private:
    QString table_name;

};

#endif // LOGIC_USER_H
