#include "edit_member_details.h"
#include "ui_edit_member_details.h"

edit_member_details::edit_member_details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit_member_details)
{
    ui->setupUi(this);
}

edit_member_details::~edit_member_details()
{
    delete ui;
}

void edit_member_details::on_pushButton_Search_clicked()
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

void edit_member_details::on_tableView_activated(const QModelIndex &index)
{
    //QString id = ui->tableView->model()->data(index).toString();
    QString cell = ui->tableView->model()->data(index).toString();
    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    QString id = ui->tableView->model()->index(rowidx , 0).data().toString();


    qDebug()<<id;
    if(id.isNull())
    {
        QMessageBox::critical(this,tr("error::"),"Please Search and Select a member ID");
    }
    else
    {
        QString name,area,address, mobile_no;
        ui->member_id->setText(id);
        db = new gdm_database();
        db->connOpen();
        QSqlQuery qry;
        qry.prepare("SELECT name,area,address,mobile_no from members WHERE member_id=UPPER('"+id+"')");
        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit_name->setText(qry.value(0).toString());
                ui->lineEdit_area->setText(qry.value(1).toString());
                ui->lineEdit_mobile->setText(qry.value(3).toString());
                ui->textEdit_address->setText(qry.value(2).toString());
            }
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
        db->connClose();
    }
}

void edit_member_details::on_pushButton_clicked()
{
    QString mbr_id,name,area,address,mobile,mbr;
    mbr_id = ui->member_id->text();
    name = ui->lineEdit_name->text();
    area = ui->lineEdit_area->text();
    mobile = ui->lineEdit_mobile->text();
    address = ui->textEdit_address->toPlainText();
    address.remove("\'");
    address.remove("\"");
    if(mbr_id == "[select a member]")
    {
        QMessageBox::critical(this,tr("error::"),"Please click 'Search' and select a member ID ");
    }

    if(name.isEmpty() || area.isEmpty() || mobile.isEmpty() || address.isEmpty() )
    {
        QMessageBox::critical(this,tr("missing information"),tr("You have missed some information!\nPlease check again."));
        qDebug() << "Missing information!!!";
    }

    else
    {
        db = new gdm_database();
        db->connOpen();

        QString pre_qry = "UPDATE members SET name='"+name+"', area='"+area+"', address='"+address+"', mobile_no='"+mobile+"' WHERE member_id='"+mbr_id+"'";
        qDebug() << pre_qry;
        db->exec_qry(pre_qry);
        db->connClose();
        qDebug()<<mbr_id+" "+name+" "+area+" "+mobile+" "+address+" "+mbr;
        this->hide();
        this->parentWidget()->setDisabled(false);
    }

}

void edit_member_details::on_pushButton_2_clicked()
{
    close();
}

void edit_member_details::on_tableView_clicked(const QModelIndex &index)
{
    on_tableView_activated(index);
}
