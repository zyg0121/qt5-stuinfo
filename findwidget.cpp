#include "findwidget.h"
#include "ui_findwidget.h"

FindWidget::FindWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::FindWidget) {
	ui->setupUi(this);
}

FindWidget::~FindWidget() {
	delete ui;
}

void FindWidget::on_returnButton_clicked() {
	emit display(0);
}

void FindWidget::on_pushButton_clicked() {
	if(ui->idlineEdit->text()=="") {
		QMessageBox::about(NULL, "反馈", "学号不能为空");
		return;
	}
	NODE pHead;
	QString name;//姓名
	long long number=ui->idlineEdit->text().toLongLong();//学号
	QString age;//年龄
	QString gender;//性别
	QString address;//地址
	long long tel; //电话号码 1XXXXXXXXXX
	QString bir;//生日
	double score;//学生成绩（0-100）
	pHead.InputStudent();
	bool pd = pHead.SearchStudent(name,number,age,gender,tel,bir,address,score);
	if(pd==false) {
		QMessageBox::about(NULL,"反馈","查无此人!");
		return;
	}
	ui->shownamelabel->setText(name);
	ui->showagelabel->setText(age);
	ui->showgenlabel->setText(gender);
	ui->showtellabel->setText(QString::number(tel));
	ui->showgradelabel->setText(QString::number(score));
	ui->showaddresslabel->setText(address);
	ui->showbirlabel->setText(bir);

	ui->idlineEdit->clear();
}
