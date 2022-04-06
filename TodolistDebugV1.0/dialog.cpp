#include "dialog.h"
#include "ui_dialog.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Event");
}

Dialog::~Dialog()
{
    delete ui;
}

/// <summary>
/// 选择添加 对添加的信息做一个判断
/// 将信息传回数据库
/// </summary>
void Dialog::on_add_clicked()
{
    //判断是否可以转发了
    if (checkInf())
    {
        emit sendInfToMain(userName, BeginDT, EndDT, BeginT, EndT, EventType, EventTitle, Note);
        this->close();
    }
    else
    {
        QMessageBox::information(this, "提示", "当前的信息不完整，请仔细检查后输入");
    }
}


/// <summary>
/// 返回原来的界面
/// 返回之前询问是否要进行保存
/// </summary>
void Dialog::on_back_clicked()
{
    if (checkInf())
    {
        int reply;
        reply = QMessageBox::question(this, "问题", "信息已经改变，您想要保存吗？");
		if (reply !=65536)
		{
			emit sendInfToMain(userName, BeginDT, EndDT, BeginT, EndT, EventType, EventTitle, Note);
			this->close();
		}
        else
        {
            this->close();
        }

    }
    else
    {
        this->close();
    }
   
}
//X号事件
void Dialog::closeEvent(QCloseEvent* event)
{
    on_back_clicked();
}

/// <summary>
/// 选择事件的类型
/// </summary>
void Dialog::on_range_clicked()//时间颜色归类按钮
{
    int i;
}

/// <summary>
/// 对当前信息做一个判断整合，判断是否可以保存
/// </summary>
/// <returns></returns>
bool Dialog::checkInf()
{
    bool st = true;
    //标准化信息和判断信息是否完全
    userName = "user";
    if (ui->name->text()!="")
    {
        EventTitle = ui->name->text();
    }
    else
    {
        return false;
    }
    //获取时间
    QString strT1 = ui->startTime->toPlainText();
    QStringList listT1 = strT1.split("/");//QString字符串分割函数
    if (listT1.size()!=4)
    {
        return false;
    }
    else
    {
        if (listT1[0].size() != 4)
        {
            return false;
        }
        else BeginDT = listT1[0];
        for (int i = 1; i <=2; i++)
        {
			if (listT1[i].size() == 1)
			{
				BeginDT = BeginDT + "-0" + listT1[i];
			}
			else if (listT1[1].size() == 2)
			{
				BeginDT = BeginDT + "-" + listT1[i];
			}
			else
			{
				return false;
			}
        }
        BeginT = listT1[3] + ":00";
    }
	QString strT2 = ui->startTime->toPlainText();
	QStringList listT2 = strT2.split("/");//QString字符串分割函数
	if (listT2.size() != 4)
	{
		return false;
	}
	else
	{
		if (listT2[0].size() != 4)
		{
			return false;
		}
		else EndDT = listT2[0];
        for (int i = 1; i <=2; i++)
        {
			if (listT2[i].size() == 1)
			{
				EndDT = EndDT + "-0" + listT2[i];
			}
			else if (listT2[1].size() == 2)
			{
				EndDT = EndDT + "-" + listT2[i];
			}
			else
			{
				return false;
			}
        }
		EndT = listT1[3] + ":00";
	}
    //默认事件类型为1;
    EventType = 1;
    //备注可以为空
    Note = ui->remarks->toPlainText();
    return st;
}

/// <summary>
/// 为窗口设置初始信息
/// </summary>
/// <param name="userName">用户名</param>
/// <param name="BeginDT">开始日期</param>
/// <param name="EndDT">结束日期</param>
/// <param name="BeginT">开始时间</param>
/// <param name="EndT">结束时间</param>
/// <param name="EventType">事件类型</param>
/// <param name="EventTitle">事件名称</param>
/// <param name="Note">备注</param>
void Dialog::set(QString userName, QString BeginDT, QString EndDT, QString BeginT, QString EndT,
    int EventType, QString EventTitle, QString Note)
{
    ui->name->setText(EventTitle);
    //将时间切割一下
    QStringList listBDt = BeginDT.split("-");
    QStringList listBT = BeginT.split(":");
	QStringList listEDt = EndDT.split("-");
	QStringList listET =EndT.split(":");
    ui->startTime->setText(listBDt[0] + "/" + listBDt[1] + "/" + listBDt[2] + "/" + listBT[0] + ":" + listBT[1]);
    ui->endTime->setText(listEDt[0] + "/" + listEDt[1] + "/" + listEDt[2] + "/" + listET[0] + ":" + listET[1]);
    ui->remarks->setText(Note);
}