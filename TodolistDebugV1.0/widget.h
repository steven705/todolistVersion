#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<dialog.h>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#pragma execution_character_set("utf-8")


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //日期发生了改变
    void DateChanged(const QDate &date);
    //搜索当日信息
    void search(QString dateStr);
    //信息栏加数据
    void updataData(QString data);
    //清楚原有数据
    void clearData();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    Dialog*dialog;
    //void showWidget();

    //与数据库相关的操作

    QSqlDatabase db;
    //链接数据库
    void connectMYSQL();

    //判断查询结果是否为空
    bool searchRet;


	//这是为了为窗口设置初始值
	QString userName;
	QString BeginDT;
	QString EndDT;
	QString BeginT;
	QString EndT;
	int EventType;
	QString EventTitle;
	QString Note;
};
#endif // WIDGET_H
