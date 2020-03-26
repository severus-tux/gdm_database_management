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
    QString pre_qry = "SELECT substr(date,7,4) as year, substr(date,4,2) as month , SUM(amount) as Total_Amount from payments GROUP BY month,year ORDER BY year,month";
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

void collection_details::on_pushButton_2_clicked()
{
    close();
}

void collection_details::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "./collection_details.pdf",
                               tr("PDF Document (*.pdf)"));
    qDebug() << fileName;


    QString strStream,strTitle;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    strTitle = "Total Collection Details";

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<center><h3>Complete Report</h3></center><br>"
            "<table>"
            "  <tr>"
            "    <td><b>Total amount collected</b></td>"
            "    <td>:</td>"
            "    <td>"+ui->amount->text()+"/-</td>"
            "  </tr>"
            "  <tr>"
            "    <td><b>Total number of members</b></td>"
            "    <td>:</td>"
            "    <td>"+ui->members_no->text()+"</td>"
            "  </tr>"
            "  <tr>"
            "    <td><b>Total number of doners</b></td>"
            "    <td>:</td>"
            "    <td>"+ui->doners_no->text()+"</td>"
            "  </tr>"
            "</table>"
            "<h4>Total collection details - monthly details : </h4>"
            "<table border=3  bordercolor='BLACK' cellspacing=2   cellpadding=5 >\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th width='35%'>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
