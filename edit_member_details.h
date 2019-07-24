#ifndef EDIT_MEMBER_DETAILS_H
#define EDIT_MEMBER_DETAILS_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "gdm_database.h"
#include <QCloseEvent>

namespace Ui {
class edit_member_details;
}

class edit_member_details : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit_member_details(QWidget *parent = nullptr);
    ~edit_member_details();

    void closeEvent (QCloseEvent *event)
    {
        this->parentWidget()->setDisabled(false);
        event->accept();
    }


private slots:
    void on_pushButton_Search_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit_member_details *ui;
    gdm_database *db;
};

#endif // EDIT_MEMBER_DETAILS_H
