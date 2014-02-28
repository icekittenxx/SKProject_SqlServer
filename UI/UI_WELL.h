#ifndef UI_WELL_H
#define UI_WELL_H

#include <QDialog>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QMessageBox>

#include "../INTERFACE/SqlQueryModel_RW.h"

#include "../LOGIC/LOGIC_USER.h"

#include "../LOGIC/WELL/LOGIC_WELL.h"
#include "../LOGIC/WELL/LOGIC_WELL_BASIC.h"

#include "UI_ADD_DATA.h"

namespace Ui {
class UI_WELL;
}

class UI_WELL : public QDialog
{
    Q_OBJECT

public:
    explicit UI_WELL(QWidget *parent = 0);
    ~UI_WELL();

private slots:
    void on_TABLEVIEW_clicked(const QModelIndex &index);

    void on_BUTTON_QUERY_clicked();

    void on_BUTTON_ADD_clicked();

    void on_BUTTON_DELETE_clicked();

    void on_COMBO_PAGE_SIZE_activated(const QString &arg1);

    void on_BUTTON_TURN_TO_FIRST_PAGE_clicked();

    void on_BUTTON_TURN_TO_PREVIOUS_PAGE_clicked();

    void on_BUTTON_TURN_TO_NEXT_PAGE_clicked();

    void on_BUTTON_TURN_TO_LAST_PAGE_clicked();

    void on_BUTTON_TURN_TO_DESIGNATED_PAGE_clicked();

    void on_SELECT_WELL_clicked();

    void on_SELECT_WELL_BASIC_clicked();

private:
    Ui::UI_WELL *ui;

    SqlQueryModel_RW *model_rw;

    int current_column;
    int current_row;

    QVector<QString> column_name;
    int primary_key_column;
    QString table_name;

    UI_ADD_DATA ui_add_data;

    int page_size;
    int page_number;
    int all_page_number;
    int row_count;
};

#endif // UI_WELL_H
