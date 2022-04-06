/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *back;
    QTextEdit *textEdit;
    QPushButton *add;
    QTextEdit *startTime;
    QTextEdit *endTime;
    QPushButton *range;
    QTextEdit *remarks;
    QLineEdit *name;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(360, 582);
        back = new QPushButton(Dialog);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 0, 81, 31));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 0, 151, 31));
        add = new QPushButton(Dialog);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(260, 0, 91, 31));
        startTime = new QTextEdit(Dialog);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setGeometry(QRect(10, 120, 341, 61));
        endTime = new QTextEdit(Dialog);
        endTime->setObjectName(QString::fromUtf8("endTime"));
        endTime->setGeometry(QRect(10, 200, 341, 71));
        range = new QPushButton(Dialog);
        range->setObjectName(QString::fromUtf8("range"));
        range->setGeometry(QRect(10, 280, 341, 41));
        remarks = new QTextEdit(Dialog);
        remarks->setObjectName(QString::fromUtf8("remarks"));
        remarks->setGeometry(QRect(10, 340, 341, 231));
        name = new QLineEdit(Dialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(12, 40, 341, 71));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        back->setText(QCoreApplication::translate("Dialog", "\350\277\224\345\233\236", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">\346\226\260\345\273\272\344\272\213\351\241\271</span></p></body></html>", nullptr));
        add->setText(QCoreApplication::translate("Dialog", "\346\267\273\345\212\240", nullptr));
        startTime->setPlaceholderText(QCoreApplication::translate("Dialog", "\345\274\200\345\247\213\346\227\266\351\227\264 \346\240\274\345\274\217\357\274\2322022/03/05/19\357\274\23200", nullptr));
        endTime->setPlaceholderText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237\346\227\266\351\227\264 \346\240\274\345\274\217\357\274\2322022/03/05/20\357\274\23200", nullptr));
        range->setText(QCoreApplication::translate("Dialog", "\344\272\213\344\273\266\345\275\222\347\261\273", nullptr));
        remarks->setPlaceholderText(QCoreApplication::translate("Dialog", "\345\244\207\346\263\250\357\274\232", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("Dialog", "\344\272\213\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
