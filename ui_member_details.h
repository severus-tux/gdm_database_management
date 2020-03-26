/********************************************************************************
** Form generated from reading UI file 'member_details.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBER_DETAILS_H
#define UI_MEMBER_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_member_details
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *area;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *mobil_no;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QTextBrowser *textBrowser_address;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *member_status;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *amount;
    QTableView *tableView_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_Search;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *member_details)
    {
        if (member_details->objectName().isEmpty())
            member_details->setObjectName(QString::fromUtf8("member_details"));
        member_details->resize(964, 598);
        centralwidget = new QWidget(member_details);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout->addWidget(label_13);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_2->addWidget(name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        area = new QLabel(centralwidget);
        area->setObjectName(QString::fromUtf8("area"));

        horizontalLayout_3->addWidget(area);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        mobil_no = new QLabel(centralwidget);
        mobil_no->setObjectName(QString::fromUtf8("mobil_no"));

        horizontalLayout_4->addWidget(mobil_no);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        textBrowser_address = new QTextBrowser(centralwidget);
        textBrowser_address->setObjectName(QString::fromUtf8("textBrowser_address"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(textBrowser_address->sizePolicy().hasHeightForWidth());
        textBrowser_address->setSizePolicy(sizePolicy);
        textBrowser_address->setMaximumSize(QSize(246, 97));

        horizontalLayout_5->addWidget(textBrowser_address);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        member_status = new QLabel(centralwidget);
        member_status->setObjectName(QString::fromUtf8("member_status"));

        horizontalLayout_7->addWidget(member_status);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        amount = new QLabel(centralwidget);
        amount->setObjectName(QString::fromUtf8("amount"));

        horizontalLayout_8->addWidget(amount);


        verticalLayout->addLayout(horizontalLayout_8);

        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout->addWidget(tableView_2);


        horizontalLayout_9->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);

        pushButton_Search = new QPushButton(centralwidget);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));

        horizontalLayout_6->addWidget(pushButton_Search);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);


        horizontalLayout_9->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_10->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_10->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_10);

        member_details->setCentralWidget(centralwidget);

        retranslateUi(member_details);
        QObject::connect(lineEdit_5, SIGNAL(returnPressed()), pushButton_Search, SLOT(click()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(member_details);
    } // setupUi

    void retranslateUi(QMainWindow *member_details)
    {
        member_details->setWindowTitle(QCoreApplication::translate("member_details", "Member Details", nullptr));
        label_13->setText(QCoreApplication::translate("member_details", "Member id", nullptr));
        label->setText(QCoreApplication::translate("member_details", "Name                     :", nullptr));
        name->setText(QCoreApplication::translate("member_details", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("member_details", "Area                        :", nullptr));
        area->setText(QCoreApplication::translate("member_details", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("member_details", "Mobile Number  :", nullptr));
        mobil_no->setText(QCoreApplication::translate("member_details", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("member_details", "Address                 :", nullptr));
        label_5->setText(QCoreApplication::translate("member_details", "Member/Doner  :", nullptr));
        member_status->setText(QCoreApplication::translate("member_details", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("member_details", "Total Amount Paid :", nullptr));
        amount->setText(QCoreApplication::translate("member_details", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("member_details", "Search Member", nullptr));
        label_8->setText(QCoreApplication::translate("member_details", "Name", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("member_details", "Search", nullptr));
        pushButton->setText(QCoreApplication::translate("member_details", "Get Details", nullptr));
        pushButton_3->setText(QCoreApplication::translate("member_details", "Export as PDF", nullptr));
        pushButton_2->setText(QCoreApplication::translate("member_details", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class member_details: public Ui_member_details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBER_DETAILS_H
