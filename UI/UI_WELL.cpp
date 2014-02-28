#include "UI_WELL.h"
#include "ui_UI_WELL.h"

UI_WELL::UI_WELL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UI_WELL)
{
    ui->setupUi(this);
    ui->EDIT_COLUMN->setEnabled(false);

    page_size = 5;
}

UI_WELL::~UI_WELL()
{
    delete ui;
}

void UI_WELL::on_TABLEVIEW_clicked(const QModelIndex &index)
{
    ui->EDIT_COLUMN->setText(column_name[index.column()]);
    current_column = index.column();
    current_row = index.row();
}

void UI_WELL::on_BUTTON_QUERY_clicked()
{
    QString val = ui->EDIT_VALUE->text();

    page_number = 0;
    ui->EDIT_PAGE_NUMBER->setText("1");
    model_rw->set_page_number(0);

    model_rw->query_one_column(column_name[current_column], val);

    row_count = model_rw->get_row_count();
    page_number = model_rw->get_page_number();
    all_page_number = row_count / page_size;
    if(all_page_number * page_size != row_count)
    {
        all_page_number ++;
    }
    QString LABEL_SHOW_PAGE = QString::number(all_page_number, 10);
    ui->LABEL_ALL_PAGE->setText("/" + LABEL_SHOW_PAGE);
}

void UI_WELL::on_BUTTON_ADD_clicked()
{
    ui_add_data.add_table(table_name, column_name, primary_key_column);

    page_number = 0;
    model_rw->set_page_number(0);
    ui->EDIT_PAGE_NUMBER->setText("1");

    if(ui_add_data.exec() == QDialog::Accepted)
        model_rw->refresh();

    row_count = model_rw->get_row_count();
    page_number = model_rw->get_page_number();
    all_page_number = row_count / page_size;
    if(all_page_number * page_size != row_count)
    {
        all_page_number ++;
    }
    QString LABEL_SHOW_PAGE = QString::number(all_page_number, 10);
    ui->LABEL_ALL_PAGE->setText("/" + LABEL_SHOW_PAGE);
}

void UI_WELL::on_BUTTON_DELETE_clicked()
{
    int ok = QMessageBox::warning(this,tr("Delete cuurent row!"),tr("Are you sure to delete current row?"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        page_number = 0;
        ui->EDIT_PAGE_NUMBER->setText("1");
        model_rw->set_page_number(0);

        QModelIndex index = model_rw->index(current_row, primary_key_column);
        QString pri_key_val = model_rw->itemData(index).begin().value().toString();
        model_rw->delete_one_column(pri_key_val);
    }

    row_count = model_rw->get_row_count();
    page_number = model_rw->get_page_number();
    all_page_number = row_count / page_size;
    if(all_page_number * page_size != row_count)
    {
        all_page_number ++;
    }
    QString LABEL_SHOW_PAGE = QString::number(all_page_number, 10);
    ui->LABEL_ALL_PAGE->setText("/" + LABEL_SHOW_PAGE);
}

void UI_WELL::on_BUTTON_TURN_TO_FIRST_PAGE_clicked()
{
    page_number = 0;
    ui->EDIT_PAGE_NUMBER->setText("1");
    model_rw->set_page_number(0);
    model_rw->refresh();
}

void UI_WELL::on_BUTTON_TURN_TO_PREVIOUS_PAGE_clicked()
{
    if(page_number > 0)
    {
        page_number = page_number - 1;
        ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
        model_rw->set_page_number(page_number);
        model_rw->refresh();
    }
}

void UI_WELL::on_BUTTON_TURN_TO_NEXT_PAGE_clicked()
{
    if(page_number < all_page_number - 1)
    {
        page_number = page_number + 1;
        ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
        model_rw->set_page_number(page_number);
        model_rw->refresh();
    }
}

void UI_WELL::on_BUTTON_TURN_TO_LAST_PAGE_clicked()
{
    page_number = all_page_number - 1;
    ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
    model_rw->set_page_number(page_number);
    model_rw->refresh();
}

void UI_WELL::on_BUTTON_TURN_TO_DESIGNATED_PAGE_clicked()
{
    bool change_flag;
    int temp_page_num = ui->EDIT_PAGE_NUMBER->text().toInt(&change_flag, 10);
    if(temp_page_num > all_page_number || temp_page_num < 1)
    {
        ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
    }
    else
    {
        page_number = temp_page_num - 1;
        model_rw->set_page_number(page_number);
        model_rw->refresh();
    }
}

void UI_WELL::on_SELECT_WELL_clicked()
{
    //LOGIC_USER table;
    LOGIC_WELL table;

    table_name = table.table_name;
    column_name = table.column_name;
    primary_key_column = table.primary_key_column;

    model_rw = new SqlQueryModel_RW(table_name, column_name, primary_key_column, page_size);
    ui->TABLEVIEW->setModel(model_rw);

    row_count = model_rw->get_row_count();
    page_number = model_rw->get_page_number();
    ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
    all_page_number = row_count / page_size;
    if(all_page_number * page_size != row_count)
    {
        all_page_number ++;
    }
    ui->LABEL_ALL_PAGE->setText("/" + QString::number(all_page_number, 10));

    ui->EDIT_COLUMN->setText(column_name[primary_key_column]);
    current_column = primary_key_column;
    //qDebug()<<model_rw->headerData(0, Qt::Horizontal, Qt::DisplayRole);
}

void UI_WELL::on_SELECT_WELL_BASIC_clicked()
{
    LOGIC_WELL_BASIC table;

    table_name = table.table_name;
    column_name = table.column_name;
    primary_key_column = table.primary_key_column;

    model_rw = new SqlQueryModel_RW(table_name, column_name, primary_key_column, page_size);
    ui->TABLEVIEW->setModel(model_rw);

    row_count = model_rw->get_row_count();
    page_number = model_rw->get_page_number();
    ui->EDIT_PAGE_NUMBER->setText(QString::number(page_number + 1, 10));
    all_page_number = row_count / page_size;
    if(all_page_number * page_size != row_count)
    {
        all_page_number ++;
    }
    ui->LABEL_ALL_PAGE->setText("/" + QString::number(all_page_number, 10));

    ui->EDIT_COLUMN->setText(column_name[primary_key_column]);
    current_column = primary_key_column;
}
