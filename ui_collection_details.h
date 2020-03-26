/********************************************************************************
** Form generated from reading UI file 'collection_details.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLECTION_DETAILS_H
#define UI_COLLECTION_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collection_details
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *amount;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *members_no;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *doners_no;
    QLabel *label_7;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *collection_details)
    {
        if (collection_details->objectName().isEmpty())
            collection_details->setObjectName(QString::fromUtf8("collection_details"));
        collection_details->resize(435, 385);
        centralwidget = new QWidget(collection_details);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        amount = new QLabel(centralwidget);
        amount->setObjectName(QString::fromUtf8("amount"));

        horizontalLayout->addWidget(amount);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        members_no = new QLabel(centralwidget);
        members_no->setObjectName(QString::fromUtf8("members_no"));

        horizontalLayout_2->addWidget(members_no);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doners_no = new QLabel(centralwidget);
        doners_no->setObjectName(QString::fromUtf8("doners_no"));

        horizontalLayout_3->addWidget(doners_no);


        verticalLayout->addLayout(horizontalLayout_3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        collection_details->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(collection_details);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        collection_details->setStatusBar(statusbar);

        retranslateUi(collection_details);

        QMetaObject::connectSlotsByName(collection_details);
    } // setupUi

    void retranslateUi(QMainWindow *collection_details)
    {
        collection_details->setWindowTitle(QCoreApplication::translate("collection_details", "Collection Details", nullptr));
        label->setText(QCoreApplication::translate("collection_details", "Total Amount                                                 :", nullptr));
        amount->setText(QCoreApplication::translate("collection_details", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("collection_details", "Total number of members                        :", nullptr));
        members_no->setText(QCoreApplication::translate("collection_details", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("collection_details", "Total number of doners                             :", nullptr));
        doners_no->setText(QCoreApplication::translate("collection_details", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("collection_details", "Monthly Collection Details :", nullptr));
        pushButton->setText(QCoreApplication::translate("collection_details", "Export as PDF", nullptr));
        pushButton_2->setText(QCoreApplication::translate("collection_details", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class collection_details: public Ui_collection_details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLECTION_DETAILS_H
