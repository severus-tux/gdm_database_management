#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gdm_database.h>
#include "member_details_input.h"
#include "payment_input.h"
#include "member_details.h"
#include "collection_details.h"
#include "edit_member_details.h"
#include "edit_payment.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    gdm_database *new_db;
//    int max_member_id;
//    int max_doner_id;
};

#endif // MAINWINDOW_H
