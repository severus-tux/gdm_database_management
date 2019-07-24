#ifndef MEMBER_DETAILS_H
#define MEMBER_DETAILS_H

#include <QMainWindow>
#include <QCloseEvent>
#include "gdm_database.h"
#include <QSqlQueryModel>

namespace Ui {
class member_details;
}

class member_details : public QMainWindow
{
    Q_OBJECT

public:
    explicit member_details(QWidget *parent = nullptr);
    ~member_details();

    void closeEvent (QCloseEvent *event)
    {
        this->parentWidget()->setDisabled(false);
        event->accept();
    }

private slots:
    void on_member_details_destroyed();

    void on_pushButton_Search_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::member_details *ui;
    gdm_database *db;
};

#endif // MEMBER_DETAILS_H
