#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    create_new_database();
    //qDebug() << "Start of all\n";
//    max_doner_id = 0;
//    max_member_id = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_new_database()
{
    new_db = new gdm_database();
    new_db->create_new_db();
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery qry;
    this->setDisabled(true);
    payment_input *pmt_input = new payment_input(this);
    pmt_input->show();
    //new_db->input_db("members.csv","members",true);

}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery qry;
    this->setDisabled(true);
    member_details_input *mbr_input = new member_details_input(this);
    mbr_input->show();
    //new_db->input_db("members.csv","members",true);

}

void MainWindow::on_pushButton_4_clicked()
{
    this->setDisabled(true);
    //this->hide();
    member_details *mbr_details = new member_details(this);
    mbr_details->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->setDisabled(true);
    //this->hide();
    collection_details *coll_details = new collection_details(this);
    coll_details->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->setDisabled(true);
    edit_member_details *edit_details = new edit_member_details(this);
    edit_details->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    this->setDisabled(true);
    edit_payment *edit_pymt = new edit_payment(this);
    edit_pymt->show();
}
