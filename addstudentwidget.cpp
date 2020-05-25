#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"

AddStudentWidget::AddStudentWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddStudentWidget) {
	ui->setupUi(this);
}

AddStudentWidget::~AddStudentWidget() {
	delete ui;
}

void AddStudentWidget::on_returnButton_clicked() {
	emit display(0);
}

void AddStudentWidget::on_addButton_clicked() {
	ui->namelineEdit->setFocus();
	QString name = ui->namelineEdit->text().trimmed();
	long long number = ui->idlineEdit->text().toLongLong();
	QString age = ui->agelineEdit->text().trimmed();
	QString gender = ui->comboBox->currentIndex()==0 ? "男" : "女";
	long long tel = ui->tellineEdit->text().toLongLong();
	QString bir = ui->birlineEdit->text().trimmed();
	QString address = ui->addresslineEdit->text().trimmed();
	double grade = ui->gradelineEdit->text().toDouble();

	if(ui->namelineEdit->text()=="" || ui->idlineEdit->text()=="" || ui->agelineEdit->text()=="" || ui->tellineEdit->text()=="" || ui->birlineEdit->text()=="" || ui->addresslineEdit->text()=="" || ui->gradelineEdit->text()=="") {
		QMessageBox::about(NULL, "反馈", "存在空项");
		return;
	}
	if(grade < 0 || grade >100) { //判断分数合理性
		QMessageBox::about(NULL, "反馈", "分数需在0~100区间");
		return;
	}
	QFile file("stuinfo.txt");
	file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
	if(!file.isOpen()) {
		QMessageBox::about(NULL, "反馈", "数据文件打开失败");
		return;
	}
	QTextStream out(&file);
	out<<name<<" "<<number<<" "<<age<<" "<<gender<<" "<<tel<<" "<<bir<<" "<<address<<" "<<grade<<"\n";
	file.close();
	QMessageBox::about(NULL,"反馈","成功保存");
	ui->namelineEdit->clear();
	ui->idlineEdit->clear();
	ui->agelineEdit->clear();
	ui->tellineEdit->clear();
	ui->birlineEdit->clear();
	ui->addresslineEdit->clear();
	ui->gradelineEdit->clear();

}
