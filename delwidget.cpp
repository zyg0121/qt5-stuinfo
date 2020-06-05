#include "delwidget.h"
#include "ui_delwidget.h"

#include "node.h"
DelWidget::DelWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DelWidget) {
	ui->setupUi(this);
}

DelWidget::~DelWidget() {
	delete ui;
}

void DelWidget::on_deletepushButton_clicked() {
	if(ui->idlineEdit->text()=="") {
		QMessageBox::about(NULL, "反馈", "学号不得为空");
		return;
	}
	NODE pHead;
    pHead.InputStudent();//从文件读入学生信息
    long long number = ui->idlineEdit->text().toLongLong();//从文本框获取信息
    pHead.DeleteStudent(number);//在链表中删除学生信息
    pHead.OutputStudent();//把链表中的学生信息写入文件
    ui->idlineEdit->clear();//清空文本框
}

void DelWidget::on_returnButton_clicked() {
	emit display(0);
}
