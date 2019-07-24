#ifndef EDIT_PAYMENT_H
#define EDIT_PAYMENT_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "gdm_database.h"
#include <QCloseEvent>


namespace Ui {
class edit_payment;
}

class edit_payment : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit_payment(QWidget *parent = nullptr);
    ~edit_payment();

    void closeEvent (QCloseEvent *event)
    {
        this->parentWidget()->setDisabled(false);
        event->accept();
    }

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit_payment *ui;
    gdm_database *db;
};

#endif // EDIT_PAYMENT_H
