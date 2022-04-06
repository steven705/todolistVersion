#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    //检查信息是否完整
    bool checkInf();
    //设置初始值
	void set(QString userName, QString BeginDT, QString EndDT, QString BeginT, QString EndT,
		int EventType, QString EventTitle, QString Note);


private slots:
    //添加按钮事件
    void on_add_clicked();
    //返回按钮事件
    void on_back_clicked();
    //事件类型？
    void on_range_clicked();

signals:
	//将消息传送回todolist界面
	void sendInfToMain(QString userName, QString BeginDT, QString EndDT, QString BeginT, QString EndT,
		int EventType, QString EventTitle, QString Note);

protected:
    //X号事件
    void closeEvent(QCloseEvent* event);

private:
    Ui::Dialog *ui;

    //存储各项信息
    QString userName;
    QString BeginDT;
    QString EndDT;
    QString BeginT;
    QString EndT;
    int EventType;
    QString EventTitle;
    QString Note;

};

#endif // DIALOG_H
