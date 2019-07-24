#include "member_details.h"
#include "ui_member_details.h"

member_details::member_details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::member_details)
{
    ui->setupUi(this);
}

member_details::~member_details()
{
    delete ui;
}


void member_details::on_member_details_destroyed()
{

}

void member_details::on_pushButton_Search_clicked()
{
    //search and view members
    db = new gdm_database();
    db->connOpen();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    QString pre_qry = "SELECT member_id,name,area FROM members WHERE UPPER(name) LIKE UPPER('%"+ui->lineEdit_5->text()+"%')";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    //setting col width manually
    {
        ui->tableView->setColumnWidth(0,105);
        ui->tableView->setColumnWidth(1,220);
        ui->tableView->setColumnWidth(2,110);
    }

    db->connClose();
    qDebug() << (modal->rowCount());
}

void member_details::on_pushButton_clicked()
{
    QString name,id,area,address,membership, mobile_no;
    int count=0;
    db = new gdm_database();
    db->connOpen();
    QSqlQuery qry;
    id=ui->lineEdit->text();
    qry.prepare("SELECT name,area,address,mobile_no,member from members WHERE member_id=UPPER('"+id+"')");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->name->setText(qry.value(0).toString());
            ui->area->setText(qry.value(1).toString());
            ui->mobil_no->setText(qry.value(3).toString());
            ui->textBrowser_address->setText(qry.value(2).toString());

            if(qry.value(4).toString() == "TRUE")
            {
                ui->member_status->setText("Member");
            }
            else
            {
                ui->member_status->setText("Doner");
            }
            count++;
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    if(count!=1)
    {
        QMessageBox::critical(this,tr("error::"),"Invalid Id");
    }
    //Setting Table
    QSqlQueryModel *modal = new QSqlQueryModel();
    QString pre_qry = "SELECT date,book_no,rcpt_no,amount from payments WHERE id = UPPER('"+id+"')";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView_2->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView_2->setModel(modal);

    //setting col width manually
    {
        ui->tableView_2->setColumnWidth(0,115);
        ui->tableView_2->setColumnWidth(1,100);
        ui->tableView_2->setColumnWidth(2,110);
        ui->tableView_2->setColumnWidth(3,120);
    }

    qDebug() << (modal->rowCount());
    //Done

    qry.prepare("SELECT COALESCE(sum(amount), 0) FROM payments WHERE id = '"+id+"'");
    qry.exec();
    while (qry.next())
    {
        ui->amount->setText(qry.value(0).toString());
    }


    //qDebug()<< "";
    db->connClose();


}

void member_details::on_pushButton_2_clicked()
{
    close();
}

//void member_details::on_tableView_clicked(const QModelIndex &index)
//{
//    QString selected_str = ui->tableView->model()->index(index.row(),0).data().toString();
//    qDebug() << selected_str;
//}

void member_details::on_tableView_activated(const QModelIndex &index)
{
    //QString id = ui->tableView->model()->data(index).toString();

    QString cell = ui->tableView->model()->data(index).toString();
    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    QString id = ui->tableView->model()->index(rowidx , 0).data().toString();

    qDebug()<<id;

    QString name,area,address,membership, mobile_no;
    int count=0;
    db = new gdm_database();
    db->connOpen();
    QSqlQuery qry;
    if(id.isNull())
    {
        id=ui->lineEdit->text();
    }
    ui->lineEdit->setText(id);
    qry.prepare("SELECT name,area,address,mobile_no,member from members WHERE member_id=UPPER('"+id+"')");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->name->setText(qry.value(0).toString());
            ui->area->setText(qry.value(1).toString());
            ui->mobil_no->setText(qry.value(3).toString());
            ui->textBrowser_address->setText(qry.value(2).toString());

            if(qry.value(4).toString() == "TRUE")
            {
                ui->member_status->setText("Member");
            }
            else
            {
                ui->member_status->setText("Doner");
            }
            count++;
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    if(count!=1)
    {
        QMessageBox::critical(this,tr("error::"),"Invalid Id");
    }
    //Setting Table
    QSqlQueryModel *modal = new QSqlQueryModel();
    QString pre_qry = "SELECT date,book_no,rcpt_no,amount from payments WHERE id = UPPER('"+id+"')";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView_2->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView_2->setModel(modal);

    //setting col width manually
    {
        ui->tableView_2->setColumnWidth(0,115);
        ui->tableView_2->setColumnWidth(1,100);
        ui->tableView_2->setColumnWidth(2,110);
        ui->tableView_2->setColumnWidth(3,120);
    }

    qDebug() << (modal->rowCount());
    //Done

    qry.prepare("SELECT COALESCE(sum(amount), 0) FROM payments WHERE id = '"+id+"'");
    qry.exec();
    while (qry.next())
    {
        ui->amount->setText(qry.value(0).toString());
    }


    //qDebug()<< "";
    db->connClose();
}
