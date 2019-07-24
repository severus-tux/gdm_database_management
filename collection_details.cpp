#include "collection_details.h"
#include "ui_collection_details.h"

collection_details::collection_details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::collection_details)
{
    ui->setupUi(this);
    db = new gdm_database();
    db->connOpen();

    QSqlQuery qry;
    //Setting Table
    QSqlQueryModel *modal = new QSqlQueryModel();
    QString pre_qry = "SELECT strftime('%Y', date) as year,strftime('%m', date) as month , SUM(amount) as Total_Amount from payments GROUP BY month,year ORDER BY year,month";
    qry.prepare(pre_qry);
    qry.exec();
    ui->tableView->setWordWrap(true);
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    //setting col width manually
    {
        ui->tableView->setColumnWidth(0,123);
        ui->tableView->setColumnWidth(1,120);
        ui->tableView->setColumnWidth(2,150);
        //ui->tableView->setColumnWidth(3,120);
    }

    qDebug() << (modal->rowCount());
    //Done

    qry.clear();
    pre_qry = "SELECT SUM(amount) as total from payments";
    qry.prepare(pre_qry);
    qry.exec();
    qry.next();
    ui->amount->setText(qry.value(0).toString());
    qry.clear();

    pre_qry = "select count(*) from members where member='TRUE'";
    qry.prepare(pre_qry);
    qry.exec();
    qry.next();
    ui->members_no->setText(qry.value(0).toString());
    qry.clear();

    pre_qry = "select count(*) from members where member='FALSE'";
    qry.prepare(pre_qry);
    qry.exec();
    qry.next();
    ui->doners_no->setText(qry.value(0).toString());
    qry.clear();

    db->connClose();
}

collection_details::~collection_details()
{
    delete ui;
}

void collection_details::on_collection_details_destroyed()
{

}
