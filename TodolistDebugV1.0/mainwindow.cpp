#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ToDolistV1.0");
    this->setFixedSize(1000,600);
    myCalwidget=new CalendarWidget(this);
    myCalwidget->move(0,100);
    myCalwidget->resize(600, 500);
    myTodoWidget=new Widget(this);
    myTodoWidget->move(605,0);

    //获取当前日期进行显示
    QDateTime dt;
	QDate date;
	dt.setDate(date.currentDate());
	QString currentDate = dt.toString("yyyy-MM-dd");
    date = changeFromStr(currentDate);
	myTodoWidget->DateChanged(date);
    myTodoWidget->search(currentDate);

    //接收传过来的消息
    connect(myCalwidget,&CalendarWidget::sendDayToMain,[&](QString str)
    {
        //设置日期
        QDate date = changeFromStr(str);
        myTodoWidget->DateChanged(date);
        myTodoWidget->clearData();
        myTodoWidget->search(str);
    });
}
//将str转换为Qdate
QDate MainWindow::changeFromStr(QString str)
{
	QStringList list = str.split("-");//QString字符串分割函数
	int year = list[0].toInt();
	int month = list[1].toInt();
	int day = list[2].toInt();
	QDate date(year, month, day);
    return date;
}
MainWindow::~MainWindow()
{
    delete ui;
}

