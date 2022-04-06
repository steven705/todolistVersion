#include "widget.h"
#include "ui_widget.h"
#include<QColor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //保证上面没有数据
    //连接服务器
    connectMYSQL();
}

/// <summary>
/// 调出主界面？
/// </summary>
void showWidget()
{
   /* view= new Widget(this);
    Widget->show();*/
}
/// <summary>
/// 设置标头日期
/// </summary>
/// <param name="date"> 传入的日期</param>
void Widget::DateChanged(const QDate &date)
{
    ui->dateEdit->setDate(date);
}
/// <summary>
/// 查询当天的信息
/// </summary>
/// <param name="dateStr"></param>
void Widget::search(QString dateStr)
{
    QSqlQuery query=QSqlQuery(db);
    QString str_exec= QStringLiteral("select * from infTodo where BeginDT = '%1'").arg(dateStr);
    query.exec(str_exec);
    //查询到结果了
    QString str_eventTitle;
    QString str_beginDate;
    QString str_endDate;
    QString str_beginTime;
    QString str_endTime;
    QString str_note;
    //将第一个信息赋值给新窗口
    int i = 0;
    searchRet = false;
    while(query.next())
    {
      searchRet = true;
      str_eventTitle=query.value(5).toString();
      str_beginDate = query.value(1).toString();
      str_endDate = query.value(2).toString();
      str_beginTime = query.value(3).toString();
      str_endTime= query.value(4).toString();
      str_beginTime.resize(8);
      str_endTime.resize(8);
      str_note = query.value(7).toString();
      updataData(str_eventTitle);
      /*updataData("开始日期：" + str_beginDate);
      updataData("结束日期：" + str_endDate);
      updataData("开始时间：" + str_beginTime);
      updataData("结束时间：" + str_endTime);
      updataData("备注：    " + str_note);*/
      updataData(str_beginDate);
      updataData(str_endDate);
      updataData(str_beginTime);
      updataData(str_endTime);
      updataData(str_note);
      if (i==0)
      {
          userName = query.value(0).toString();
          BeginDT = str_beginDate;
          BeginT = str_beginTime;
          EndDT = str_endDate;
          EndT = str_endTime;
          EventTitle = str_eventTitle;
          EventType = query.value(6).toInt();
          Note = str_note;
          i++;
      }
    }
}
/// <summary>
/// 点击加号出现添加信息窗口
/// </summary>
void Widget::on_pushButton_clicked()
{
	dialog = new Dialog();
    //当天有信息才设置初始值
    if (searchRet)
    {
        dialog->set(userName, BeginDT, EndDT, BeginT, EndT, EventType, EventTitle, Note);
    }
    //dailog传来信息实现插入 完全一样也没问题 数据库自动就不执行了
	connect(dialog, &Dialog::sendInfToMain, [&](QString userName, QString BeginDT,
        QString EndDT, QString BeginT, QString EndT,int EventType, QString EventTitle, QString Note) 
        {
            //将数据加到数据库中去
			QString sql =
                QString("insert into infTodo(userName ,BeginDT,EndDT,BeginT,EndT ,EventTitle ,EventType,Note) values('%1', '%2', '%3', '%4','%5','%6',%7,'%8')")
                .arg(userName).arg(BeginDT).arg(EndDT).arg(BeginT).arg(EndT).arg(EventTitle).arg(EventType).arg(Note);
			QSqlQuery query;
			query.exec(sql);
        });
	dialog->exec();
	delete dialog;
}

/// <summary>
/// 更新当前日期
/// </summary>
/// <param name="data">传入的日期</param>
void Widget::updataData(QString data)
{
    ui->textEdit->append(data);
}

/// <summary>
/// 初始化连接数据库
/// </summary>
void Widget::connectMYSQL()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("47.98.181.12");
    db.setPort(3306);
    db.setDatabaseName("todolist");
    db.setUserName("user_todolist");
    db.setPassword("15377619612Lzx@");
    if (db.open())
    {
        qDebug() << "successfully!";
    }
}

void Widget::clearData()
{
    ui->textEdit->clear();
}
Widget::~Widget()
{
    delete ui;
}