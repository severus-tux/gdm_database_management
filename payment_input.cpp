#include "payment_input.h"
#include "ui_payment_input.h"

payment_input::payment_input(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::payment_input)
{
    ui->setupUi(this);
}

payment_input::~payment_input()
{
    delete ui;
}



void payment_input::on_pushButton_clicked()
{
    //qDebug() << "hi";
    //int error=0;
    int count=0;
    QString id,date,rcpt_no,book_no,amount,pre_qry,timestamp;
    db = new gdm_database();
    db->connOpen();

    id     = ui->lineEdit->text();
    date   = ui->calendarWidget->selectedDate().toString("dd-MM-yyyy");
    rcpt_no= ui->lineEdit_2->text();
    book_no= ui->lineEdit_3->text();
    amount = ui->lineEdit_4->text();
    timestamp = QString::number(QDateTime::currentSecsSinceEpoch(),10);

    if(db->db.isOpen())
    {
           QSqlQuery qry;
           //qDebug()<<"Its OPEN!";
           pre_qry="SELECT COALESCE(COUNT(*),0) FROM members WHERE member_id=UPPER('"+id+"') ";
           qry.exec(pre_qry);
           qry.next();
           count=qry.value(0).toInt();
           qDebug()<<count;
           if(count!=1)
           {
                QMessageBox::critical(this,tr("error::"),"Invalid User ID.\nPlease check.");
           }
           qry.clear();
    }

    if(id.isEmpty() || date.isEmpty() || rcpt_no.isEmpty() || book_no.isEmpty() || amount.isEmpty())
    {
        QMessageBox::critical(this,tr("missing information"),tr("You have missed some information!\nPlease check again."));
        qDebug() << "Missing information!!!";
    }

    else
    {
        pre_qry = "INSERT INTO payments VALUES ( '"+id+"' , '"+date+"' , '"+rcpt_no+"' , '"+book_no+"' , '"+amount+"' , '"+timestamp+"' ) ";
        db->exec_qry(pre_qry);
//        {
//            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
//        }
        qDebug()<<pre_qry;
        this->hide();
        this->parentWidget()->setDisabled(false);
    }
    db->connClose();

}

void payment_input::on_pushButton_Search_clicked()
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

void payment_input::on_pushButton_2_clicked()
{
    close();
}

void payment_input::on_tableView_activated(const QModelIndex &index)
{
    //QString id = ui->tableView->model()->data(index).toString();
    QString cell = ui->tableView->model()->data(index).toString();
    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    QString id = ui->tableView->model()->index(rowidx , 0).data().toString();
    ui->lineEdit->setText(id);
}

void payment_input::on_calendarWidget_activated(const QDate &date)
{
    QString sel_date = date.toString(Qt::TextDate);
    ui->selected_date->setText(sel_date);
}

void payment_input::on_calendarWidget_clicked(const QDate &date)
{
    QString sel_date = date.toString(Qt::TextDate);
    ui->selected_date->setText(sel_date);
}

void payment_input::on_tableView_clicked(const QModelIndex &index)
{
    on_tableView_activated(index);
}
