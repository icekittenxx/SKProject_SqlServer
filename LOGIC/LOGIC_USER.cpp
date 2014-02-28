#include "LOGIC_USER.h"

#include "../DB/DB_SQL.h"

LOGIC_USER::LOGIC_USER()
{
    table_name = "[User]";
    //table_name = "[SKProject].[dbo].[User]";

    primary_key_column = 0;

    column_name.push_back("[id]");
    column_name.push_back("[user_type_id]");
    column_name.push_back("[remark]");
    column_name.push_back("[organisation]");
    column_name.push_back("[creatorID]");
    column_name.push_back("[name]");
    column_name.push_back("[set]");
    column_name.push_back("[loginUserName]");
    column_name.push_back("[password]");
    column_name.push_back("[activation]");
    column_name.push_back("[Time]");
    column_name.push_back("[foreign_operationHistory_ids]");
}

bool LOGIC_USER::USER_EXIST(QString usr, QString pwd)
{
    DB_SQL query_sql;
    QString select_column;
    QVector<QString> column;
    column.push_back(column_name[7]);
    column.push_back(column_name[8]);
    select_column = query_sql.QSTRING_SELECT_COLUMN(column);

    QSqlQuery query;
    query = query_sql.SELECT_EXCUTE(select_column, table_name);

    bool flag = false;
    while(query.next())
    {
        QString ele1 = query.value(0).toString();
        QString ele2 = query.value(1).toString();

        if(usr == ele1 && pwd == ele2)
        {
            flag = true;
            break;
        }
    }

    return flag;
}
