#ifndef GDM_DATABASE_H
#define GDM_DATABASE_H

#include <QtSql>
#include <QFileInfo>
#include <QSqlQuery>
#include <QFile>
#include <QIODevice>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QObject>

class gdm_database
{
public:
    QSqlDatabase db;
    QString path;

    gdm_database();

    void create_new_db();
    void connOpen();
    void connClose();
    void input_db(QString path,QString table, bool isfile);
    QString get_value(QString variable);
    void set_value(QString variable,QString value);
    void exec_qry(QString pre_qry);
};

#endif // GDM_DATABASE_H
