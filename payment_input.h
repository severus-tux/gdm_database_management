#ifndef PAYMENT_INPUT_H
#define PAYMENT_INPUT_H

#include <QMainWindow>
#include <QCloseEvent>
#include "gdm_database.h"
#include <QSqlQueryModel>
#include <QDateTime>

namespace Ui {
class payment_input;
}

class payment_input : public QMainWindow
{
    Q_OBJECT

public:
    explicit payment_input(QWidget *parent = nullptr);
    ~payment_input();

    void closeEvent (QCloseEvent *event)
    {
        this->parentWidget()->setDisabled(false);
        event->accept();
    }

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_Search_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_calendarWidget_activated(const QDate &date);

    void on_calendarWidget_clicked(const QDate &date);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::payment_input *ui;
    gdm_database *db;
};

#endif // PAYMENT_INPUT_H
