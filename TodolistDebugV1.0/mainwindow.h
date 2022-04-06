#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"date.h"
#include"calendarwidget.h"
#include"dialog.h"
#include"widget.h"
#include<QDebug>
#include<QColorDialog>
#include<QDate>
#pragma execution_character_set("utf-8")


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //将str转换为Qdate
    QDate changeFromStr(QString str);


    Ui::MainWindow *ui;
    //日历部分
    CalendarWidget* myCalwidget;
    //显示部分
    Widget* myTodoWidget;
};
#endif // MAINWINDOW_H
