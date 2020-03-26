/********************************************************************************
** Form generated from reading UI file 'edit_payment.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_PAYMENT_H
#define UI_EDIT_PAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_payment
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_payment_id;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_mbr_id;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLabel *selected_date;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_book_no;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_rcpt_no;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_amount;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *edit_payment)
    {
        if (edit_payment->objectName().isEmpty())
            edit_payment->setObjectName(QString::fromUtf8("edit_payment"));
        edit_payment->resize(998, 620);
        centralwidget = new QWidget(edit_payment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_payment_id = new QLabel(centralwidget);
        label_payment_id->setObjectName(QString::fromUtf8("label_payment_id"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_payment_id->sizePolicy().hasHeightForWidth());
        label_payment_id->setSizePolicy(sizePolicy);
        label_payment_id->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(label_payment_id);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_mbr_id = new QLabel(centralwidget);
        label_mbr_id->setObjectName(QString::fromUtf8("label_mbr_id"));
        sizePolicy.setHeightForWidth(label_mbr_id->sizePolicy().hasHeightForWidth());
        label_mbr_id->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_mbr_id);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        horizontalLayout_6->addWidget(calendarWidget);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        selected_date = new QLabel(centralwidget);
        selected_date->setObjectName(QString::fromUtf8("selected_date"));

        horizontalLayout_9->addWidget(selected_date);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lineEdit_book_no = new QLineEdit(centralwidget);
        lineEdit_book_no->setObjectName(QString::fromUtf8("lineEdit_book_no"));

        horizontalLayout_3->addWidget(lineEdit_book_no);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_rcpt_no = new QLineEdit(centralwidget);
        lineEdit_rcpt_no->setObjectName(QString::fromUtf8("lineEdit_rcpt_no"));

        horizontalLayout_4->addWidget(lineEdit_rcpt_no);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEdit_amount = new QLineEdit(centralwidget);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));

        horizontalLayout_5->addWidget(lineEdit_amount);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(18, 539, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(631, 301));

        verticalLayout_2->addWidget(tableView);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setMinimumSize(QSize(631, 0));

        verticalLayout_3->addWidget(tableView_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_10->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 50));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton_4->setPalette(palette);

        horizontalLayout_8->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 50));

        horizontalLayout_8->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 50));

        horizontalLayout_8->addWidget(pushButton_3);


        verticalLayout_5->addLayout(horizontalLayout_8);

        edit_payment->setCentralWidget(centralwidget);

        retranslateUi(edit_payment);

        QMetaObject::connectSlotsByName(edit_payment);
    } // setupUi

    void retranslateUi(QMainWindow *edit_payment)
    {
        edit_payment->setWindowTitle(QCoreApplication::translate("edit_payment", "Edit Payment", nullptr));
        label_2->setText(QCoreApplication::translate("edit_payment", "PAYMENT ID :", nullptr));
        label_payment_id->setText(QCoreApplication::translate("edit_payment", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("edit_payment", "MEMBER ID   :", nullptr));
        label_mbr_id->setText(QCoreApplication::translate("edit_payment", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("edit_payment", "Date", nullptr));
        label_10->setText(QCoreApplication::translate("edit_payment", "Selected Date :", nullptr));
        selected_date->setText(QCoreApplication::translate("edit_payment", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("edit_payment", "Book number     ", nullptr));
        label_6->setText(QCoreApplication::translate("edit_payment", "Receipt number", nullptr));
        label_7->setText(QCoreApplication::translate("edit_payment", "Amount                ", nullptr));
        label->setText(QCoreApplication::translate("edit_payment", "Select PAYMENT_ID :", nullptr));
        label_8->setText(QCoreApplication::translate("edit_payment", "Search Member :", nullptr));
        label_9->setText(QCoreApplication::translate("edit_payment", "Name  :", nullptr));
        pushButton->setText(QCoreApplication::translate("edit_payment", "Search", nullptr));
        pushButton_4->setText(QCoreApplication::translate("edit_payment", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("edit_payment", "Update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("edit_payment", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edit_payment: public Ui_edit_payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_PAYMENT_H
