#ifndef COLLECTION_DETAILS_H
#define COLLECTION_DETAILS_H

#include <QMainWindow>
#include <QCloseEvent>
#include "gdm_database.h"

namespace Ui {
class collection_details;
}

class collection_details : public QMainWindow
{
    Q_OBJECT

public:
    explicit collection_details(QWidget *parent = nullptr);
    ~collection_details();

    void closeEvent (QCloseEvent *event)
    {
        this->parentWidget()->setDisabled(false);
        event->accept();
    }

private slots:
    void on_collection_details_destroyed();


private:
    Ui::collection_details *ui;
    gdm_database *db;
};

#endif // COLLECTION_DETAILS_H
