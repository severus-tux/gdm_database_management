#include "gdm_database.h"

gdm_database::gdm_database()
{

}

void gdm_database::create_new_db()
{
    connOpen();
    // Creating tables
    QSqlQuery query;
    query.prepare("CREATE TABLE members ( "
                  "member_id varchar(10) primary key , "
                  "name varchar(25) not null, "
                  "area varchar(20) , "
                  "address varchar(50) , "
                  "mobile_no varchar(15) , "
                  "member boolean )" );
    query.exec();

    query.prepare("CREATE TABLE payments ( "
                  "id varchar(10) , "
                  "date DATE , "
                  "rcpt_no varchar(10) , "
                  "book_no varchar(5) , "
                  "amount integer , "
                  "timestamp varchar(30) , "
                  "foreign key(id) references members(member_id) " );
    query.exec();

    query.prepare("CREATE TABLE variable_values ("
                  "variable varchar(25) primary key, "
                  "value varchar(50)");
    query.exec();
    query.clear();
    connClose();
}

void gdm_database::connOpen()
{
    QString path = "gdm_databases/gdm.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if(!db.open())
    {
        qDebug() << "[ERROR] Database: connection FAILED\n";
    }
    else
    {
        qDebug() << "[SUCCESS] Database: connection ok\n";
    }
}
void gdm_database::connClose()
{
    db.close();
    db.removeDatabase("QSQLITE");
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

}
void gdm_database::input_db(QString path,QString table, bool isfile) // if isfile is true , then Path has fath to csv file
                                                                     // Otherwile, path has *constructed* query
{
    connOpen();

    if(isfile)
    {
        //Open the ".csv" file
        QFile file(path);
        if(file.open (QIODevice::ReadOnly))
        {
            QSqlQuery qry;
            QTextStream ts (&file);

            //Travel through the csv file "excel.csv"
            db.transaction();
            while(!ts.atEnd())
            {
                QString qr = "INSERT INTO "+table+" VALUES( '";
                // split every lines on comma
                QStringList line = ts.readLine().split(',');
                /*for every values on a line,
                    append it to the INSERT request*/
                for(int i=0; i<line.length ();++i)
                {
                    qr.append(line.at(i));
                    qr.append("', '");
                }
                qr.chop(3); // remove the trailing comma ,space and '
                qr.append("); "); // close the "VALUES([...]" with a ");"
                qry.exec(qr);
            }
            db.commit();
            file.close ();
        }
    }
    else
    {

    }
    connClose();
}

QString gdm_database::get_value(QString variable)
{
    QString value;
    connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT value from variable_values where variable='"+variable+"' ");
    qry.exec();
    while (qry.next())
    {
        value=qry.value(0).toString();
        qDebug()<< variable +" <- "+value;
    }
    connClose();
    return value;
}

void gdm_database::set_value(QString variable, QString value)
{
    connOpen();
    QString pre_qry;
    QSqlQuery qry;
    pre_qry = "UPDATE variable_values SET value = '"+value+"'  WHERE variable = '"+variable+"' ";
    qDebug()<<pre_qry;
    qry.prepare(pre_qry);
    qry.exec();
    connClose();
}

void gdm_database::exec_qry(QString pre_qry)
{
    connOpen();
    QSqlQuery qry;
    qry.prepare(pre_qry);
    qry.exec();
    connClose();
}
