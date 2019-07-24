#include "member_details_input.h"
#include "ui_member_details_input.h"

member_details_input::member_details_input(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::member_details_input)
{
    ui->setupUi(this);

}

member_details_input::~member_details_input()
{
    delete ui;
}


void member_details_input::on_member_details_input_destroyed()
{

}


//connect(this, SIGNAL(finished(int)), this->parentWidget(), SLOT(show()));

void member_details_input::on_pushButton_clicked()
{
    //qDebug() << "hi";
    int error=0;
    QString mbr_id,name,area,address,mobile,mbr;

    name = ui->lineEdit_name->text();
    area = ui->lineEdit_area->text();
    mobile = ui->lineEdit_mobile->text();
    address = ui->textEdit_address->toPlainText();
    if ( ui->radioButton_mbr->isChecked() )
        mbr="TRUE";
    else if (ui->radioButton_dnr->isChecked())
        mbr="FALSE";
    else
        error = 1; // missing information

    if(name.isEmpty() || area.isEmpty() || mobile.isEmpty() || address.isEmpty() || error==1)
    {
        QMessageBox::critical(this,tr("missing information"),tr("You have missed some information!\nPlease check again."));
        qDebug() << "Missing information!!!";
    }

    else
    {
        db = new gdm_database();
        db->connOpen();
        if(mbr=="TRUE")
        {
            mbr_id = db->get_value("max_mbr_id");
            mbr_id.remove(0,3);
            max_mbr_id=mbr_id.toInt();
            max_mbr_id+=1;
            mbr_id= QString::number(max_mbr_id);
            mbr_id= "00000" + mbr_id;
            mbr_id=mbr_id.right(5);
            mbr_id="MBR"+mbr_id;
            db->set_value("max_mbr_id",mbr_id);

        }
        else
        {
            mbr_id = db->get_value("max_dnr_id");
            mbr_id.remove(0,3);
            max_dnr_id=mbr_id.toInt();
            //qDebug() << mbr_id+"%%%%%%";
            max_dnr_id=max_dnr_id+1;
            mbr_id= QString::number(max_dnr_id);
            mbr_id= "00000" + mbr_id;
            mbr_id=mbr_id.right(5);
            mbr_id="DNR"+mbr_id;
            //qDebug() << mbr_id+"%%%%%%";
            db->set_value("max_dnr_id",mbr_id);

        }

        QString pre_qry = "INSERT INTO members VALUES ( '"+mbr_id+"' , '"+name+"' , '"+area+"' , '"+address+"' , '"+mobile+"' , '"+mbr+"' ) ";
        qDebug() << pre_qry;
        db->exec_qry(pre_qry);
        db->connClose();
        qDebug()<<mbr_id+" "+name+" "+area+" "+mobile+" "+address+" "+mbr;
        this->hide();
        this->parentWidget()->setDisabled(false);
    }

}

void member_details_input::on_pushButton_2_clicked()
{
    this->hide();
    this->parentWidget()->setDisabled(false);
}
