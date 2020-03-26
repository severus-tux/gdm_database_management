#include "edit_payment.h"
#include "ui_edit_payment.h"

edit_payment::edit_payment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit_payment)
{
    ui->setupUi(this);

    //search and view members
    db = new gdm_database();
    db->connOpen();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    QString pre_qry = "SELECT timestamp as PAYMENT_ID,id as member_id,date,rcpt_no,book_no,amount from payments ORDER BY PAYMENT_ID DESC";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

//    //setting col width manually
//    {
//        ui->tableView->setColumnWidth(0,105);
//        ui->tableView->setColumnWidth(1,220);
//        ui->tableView->setColumnWidth(2,110);
//    }

    db->connClose();
    qDebug() << (modal->rowCount());
}

edit_payment::~edit_payment()
{
    delete ui;
}

void edit_payment::on_tableView_activated(const QModelIndex &index)
{
    QString pymt_id = ui->tableView->model()->data(index).toString();
    //ui->label_payment_id->setText(pymt_id);

    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    ui->label_payment_id->setText(ui->tableView->model()->index(rowidx , 0).data().toString());
    ui->label_mbr_id->setText(ui->tableView->model()->index(rowidx , 1).data().toString());
    ui->lineEdit_book_no->setText(ui->tableView->model()->index(rowidx , 4).data().toString());
    ui->lineEdit_rcpt_no->setText(ui->tableView->model()->index(rowidx , 3).data().toString());
    ui->lineEdit_amount->setText(ui->tableView->model()->index(rowidx , 5).data().toString());
    QString date= ui->tableView->model()->index(rowidx , 2).data().toString();
    ui->calendarWidget->setSelectedDate(QDate::fromString(date,"dd-MM-yyyy"));
//    ui->txt2->setText(model->index(rowidx , 1).data().toString());
//    ui->txt3->setText(model->index(rowidx , 2).data().toString());
//    ui->txt4->setText(model->index(rowidx , 3).data().toString());
}

void edit_payment::on_pushButton_clicked()
{
    //search and view members
    db = new gdm_database();
    db->connOpen();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    QString pre_qry = "SELECT member_id,name,area FROM members WHERE UPPER(name) LIKE UPPER('%"+ui->lineEdit->text()+"%')";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView_2->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView_2->setModel(modal);

    //setting col width manually
    {
        ui->tableView_2->setColumnWidth(0,135);
        ui->tableView_2->setColumnWidth(1,250);
        ui->tableView_2->setColumnWidth(2,140);
    }

    db->connClose();
    qDebug() << (modal->rowCount());
}

void edit_payment::on_tableView_2_activated(const QModelIndex &index)
{
    QString id = ui->tableView_2->model()->data(index).toString();
    int rowidx = ui->tableView_2->selectionModel()->currentIndex().row();
    ui->label_mbr_id->setText(ui->tableView_2->model()->index(rowidx , 0).data().toString());
}

void edit_payment::on_pushButton_3_clicked()
{
    close();
}

void edit_payment::on_pushButton_2_clicked()
{
    db = new gdm_database();
    db->connOpen();
    QSqlQuery qry;
    QString mbr_id,date,rcpt_no,book_no,amount,timestamp;
    timestamp = ui->label_payment_id->text();
    mbr_id = ui->label_mbr_id->text();
    rcpt_no = ui->lineEdit_rcpt_no->text();
    book_no = ui->lineEdit_book_no->text();
    amount = ui->lineEdit_amount->text();
    date   = ui->calendarWidget->selectedDate().toString("dd-MM-yyyy");

    if(timestamp.isEmpty())
    {
        QMessageBox::critical(this,tr("missing information"),tr("Please select a payment"));
    }

    else
    {
        QString pre_qry = "UPDATE payments SET id='"+mbr_id+"' , date='"+date+"' , rcpt_no='"+rcpt_no+"' , book_no='"+book_no+"' , amount='"+amount+"' WHERE timestamp='"+timestamp+"' ";
        qDebug() << pre_qry;
        db->exec_qry(pre_qry);
    }
    db->connClose();
    QMessageBox::information(this,
                             tr("Success"),
                             tr("Update Successful"),
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    this->hide();
    this->parentWidget()->setDisabled(false);
}

void edit_payment::on_calendarWidget_activated(const QDate &date)
{
    QString sel_date = date.toString(Qt::TextDate);
    ui->selected_date->setText(sel_date);
}

void edit_payment::on_calendarWidget_clicked(const QDate &date)
{
    QString sel_date = date.toString(Qt::TextDate);
    ui->selected_date->setText(sel_date);
}

void edit_payment::on_tableView_clicked(const QModelIndex &index)
{
    on_tableView_activated(index);
}

void edit_payment::on_tableView_2_clicked(const QModelIndex &index)
{
    on_tableView_2_activated(index);
}

void edit_payment::on_pushButton_4_clicked()
{
    db = new gdm_database();
    db->connOpen();
    QSqlQuery qry;
    QString timestamp;
    timestamp = ui->label_payment_id->text();

    if(timestamp.isEmpty())
    {
        QMessageBox::critical(this,tr("missing information"),tr("Please select a payment"));
    }

    else
    {
        int ret = QMessageBox::warning(this, tr("Delete Warning"),
                                       tr("This operation cannot be reversed.\n"
                                          "Do you want to delete the payment:?"),
                                       QMessageBox::Yes | QMessageBox::No,
                                       QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            QString pre_qry = "DELETE FROM payments WHERE timestamp='"+timestamp+"' ";
            qDebug() << pre_qry;
            db->exec_qry(pre_qry);
        }
    }
    db->connClose();
    QMessageBox::information(this,
                             tr("Success"),
                             tr("Deletion Successful"),
                             QMessageBox::Ok,
                             QMessageBox::Ok);
    this->hide();
    this->parentWidget()->setDisabled(false);
}
