#ifndef MEMBER_DETAILS_INPUT_H
#define MEMBER_DETAILS_INPUT_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
#include "gdm_database.h"
//#include "gdm_database.h"
#include <QSqlQueryModel>

namespace Ui {
class member_details_input;
}

class member_details_input : public QMainWindow
{
    Q_OBJECT

public:
    explicit member_details_input(QWidget *parent = nullptr);
    ~member_details_input();

private slots:
    void on_member_details_input_destroyed();

    void on_pushButton_clicked();

    void closeEvent (QCloseEvent *event)
    {
       this->parentWidget()->setDisabled(false);
       event->accept();
    }

    void on_pushButton_2_clicked();

private:
    Ui::member_details_input *ui;
    int max_mbr_id;
    int max_dnr_id;
    gdm_database *db;
};

#endif // MEMBER_DETAILS_INPUT_H
