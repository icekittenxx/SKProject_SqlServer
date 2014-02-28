#include "UI_ADD_DATA.h"
#include "ui_UI_ADD_DATA.h"

UI_ADD_DATA::UI_ADD_DATA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UI_ADD_DATA)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& Qt::WindowMaximizeButtonHint& Qt::WindowMinimizeButtonHint);
}

UI_ADD_DATA::~UI_ADD_DATA()
{
    delete ui;
}

void UI_ADD_DATA::add_table(QString tab_nam, QVector<QString> col_nam, int pri_key_col)
{
    table_name = tab_nam;
    column_name = col_nam;
    primary_key_column = pri_key_col;

    model = new QStandardItemModel;
    int column_count = column_name.count();
    model->setColumnCount(column_count);
    for(int i = 0; i < column_count; i ++)
    {
        QByteArray tempQBA = column_name[i].toLatin1();
        char *tempC = tempQBA.data();
        model->setHeaderData(i, Qt::Horizontal, tr(tempC));
    }
    QList<QStandardItem*> item;
    model->appendRow(item);
    ui->TABLEVIEW->setModel(model);
}

void UI_ADD_DATA::on_ADD_CONFIRM_clicked()
{
    int column_size = column_name.size();
    QVector<QString> value;
    QVector<bool> flag;
    for(int i = 0; i < column_size; i ++)
    {
        if(model->item(0, i) == NULL)
        {
            flag.push_back(false);
            value.push_back("NULL");
        }
        else
        {
            flag.push_back(true);
            value.push_back(model->item(0, i)->text());
        }
    }

    QVector<QString> ins_column, ins_value;
    for(int i = 0; i < column_size; i ++)
    {
        if(flag[i])
        {
            ins_column.push_back(column_name[i]);
            ins_value.push_back(value[i]);
        }
    }
    query_sql.INSERT_CONDITION_EXCUTE(ins_column, ins_value, table_name);

    accept();
}
