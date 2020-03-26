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

void member_details::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::critical(this,tr("error::"),"Please select a member to Print");
    }
    else
    {

        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                   "./"+ui->lineEdit->text()+"_details.pdf",
                                   tr("PDF Document (*.pdf)"));
        qDebug() << fileName;


        QString strStream,strTitle;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();

        strTitle = "Member Details";

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<center><h3>Member Details</h3></center><br>"
                "<table>"
                "  <tr>"
                "    <td><b>Member ID</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->lineEdit->text()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Name</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->name->text()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Mobile Number</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->mobil_no->text()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Membership Status</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->member_status->text()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Area</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->area->text()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Address</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->textBrowser_address->toHtml()+"</td>"
                "  </tr>"
                "  <tr>"
                "    <td><b>Total amount paid</b></td>"
                "    <td>:</td>"
                "    <td>"+ui->amount->text()+"</td>"
                "  </tr>"
                "</table>"
                "<h4>Donation details : </h4>"
                "<table border=3  bordercolor='BLACK' cellspacing=2   cellpadding=5 >\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
                out << QString("<th width='25%'>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument doc;
        doc.setHtml(strStream);
        //qDebug() << "****\n"+strStream+"\n****0";
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFileName(fileName);
        printer.setOutputFormat(QPrinter::PdfFormat);
        doc.print(&printer);
        printer.newPage();
    }
}

void member_details::on_tableView_clicked(const QModelIndex &index)
{
    on_tableView_activated(index);
}
