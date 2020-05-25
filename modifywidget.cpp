#include "modifywidget.h"
#include "ui_modifywidget.h"

#include "node.h"

ModifyWidget::ModifyWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ModifyWidget) {
	ui->setupUi(this);
}

ModifyWidget::~ModifyWidget() {
	delete ui;
}

void ModifyWidget::on_returnButton_clicked() {
	emit display(0);
}

void ModifyWidget::on_modifypushButton_clicked() {
	if(ui->namelineEdit->text() == "" || ui->idlineEdit->text() == "" || ui->agelineEdit->text() == "" || ui->birlineEdit->text() == "" || ui->tellineEdit->text() == "" || ui->gradelineEdit->text() == "" || ui->addresslineEdit->text() == "") {
		QMessageBox::about(NULL, "反馈", "存在空项");
		return;
	}
	NODE pHead;
	pHead.InputStudent();
	QString name = ui->namelineEdit->text().trimmed();
	long long number = ui->idlineEdit->text().toLongLong();
	QString age = ui->agelineEdit->text().trimmed();
	QString gender = ui->comboBox->currentIndex()==0 ? "男" : "女";
	long long tel = ui->tellineEdit->text().toLongLong();
	QString bir = ui->birlineEdit->text().trimmed();
	QString address = ui->addresslineEdit->text().trimmed();
	double grade = ui->gradelineEdit->text().toDouble();
	pHead.ChangeStudent(name,number,age,gender,tel,bir,address,grade);
	pHead.OutputStudent();
	ui->idlineEdit->clear();
	ui->agelineEdit->clear();
	ui->birlineEdit->clear();
	ui->tellineEdit->clear();
	ui->namelineEdit->clear();
	ui->gradelineEdit->clear();
	ui->addresslineEdit->clear();

}

void ModifyWidget::on_searchButton_clicked() {
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
	ui->namelineEdit->setText(name);
	ui->agelineEdit->setText(age);
	if(gender=="男") {
		ui->comboBox->setCurrentIndex(0);
	} else if(gender=="女") {
		ui->comboBox->setCurrentIndex(1);
	} else {
		ui->comboBox->setCurrentIndex(-1);
	}
	ui->tellineEdit->setText(QString::number(tel));
	ui->gradelineEdit->setText(QString::number(score));
	ui->addresslineEdit->setText(address);
	ui->birlineEdit->setText(bir);
}
