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
    ui->idlineEdit->setFocus();//设置指针指向学号
    //从文本框获取信息
	QString name = ui->namelineEdit->text().trimmed();
	long long number = ui->idlineEdit->text().toLongLong();
	QString age = ui->agelineEdit->text().trimmed();
	QString gender = ui->comboBox->currentIndex()==0 ? "男" : "女";
	long long tel = ui->tellineEdit->text().toLongLong();
	QString bir = ui->birlineEdit->text().trimmed();
	QString address = ui->addresslineEdit->text().trimmed();
	double grade = ui->gradelineEdit->text().toDouble();

    if(ui->namelineEdit->text()=="" || ui->idlineEdit->text()=="" || ui->agelineEdit->text()==""
            || ui->tellineEdit->text()=="" || ui->birlineEdit->text()=="" ||
            ui->addresslineEdit->text()=="" || ui->gradelineEdit->text()=="") {//判断是否有空项目
		QMessageBox::about(NULL, "反馈", "存在空项");
		return;
	}
	if(grade < 0 || grade >100) { //判断分数合理性
		QMessageBox::about(NULL, "反馈", "分数需在0~100区间");
		return;
	}
    QFile file("stuinfo.txt");//文件指针
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);//打开文件
	if(!file.isOpen()) {
		QMessageBox::about(NULL, "反馈", "数据文件打开失败");
		return;
	}
    QTextStream out(&file);//写入
	out<<name<<" "<<number<<" "<<age<<" "<<gender<<" "<<tel<<" "<<bir<<" "<<address<<" "<<grade<<"\n";
    file.close();//关闭
	QMessageBox::about(NULL,"反馈","成功保存");
    //清楚文本框信息
	ui->namelineEdit->clear();
	ui->idlineEdit->clear();
	ui->agelineEdit->clear();
	ui->tellineEdit->clear();
	ui->birlineEdit->clear();
	ui->addresslineEdit->clear();
	ui->gradelineEdit->clear();

}
