#include "sortwidget.h"
#include "ui_sortwidget.h"
#include <algorithm>


bool getStuInfo(QVector<stuinfo> &allStuInfo) {
	QFile file("stuinfo.txt");
	file.open(QIODevice::ReadOnly|QIODevice::Text);
	QTextStream inp(&file);
	if(!file.isOpen()) {
		QMessageBox::about(NULL,"反馈","数据文件打开失败");
		return false;
	}
	while(!inp.atEnd()) {
		QString name;//姓名
		long long number;//学号
		QString age;//年龄
		QString gender;//性别
		QString address;//地址
		long long tel; //电话号码 1XXXXXXXXXX
		QString bir;//生日
		double score;//学生成绩（0-100）
		inp>>name>>number>>age>>gender>>tel>>bir>>address>>score;
		allStuInfo.push_back(stuinfo(name,number,age,gender,tel,bir,address,score));
	}
	allStuInfo.pop_back();
	file.close();
	return true;
}


bool cmp_number(stuinfo a,stuinfo b) {
	return a.getnumber() < b.getnumber();
}

bool cmp_score(stuinfo a,stuinfo b) {
	return a.getscore() > b.getscore();
}


SortWidget::SortWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SortWidget) {
	ui->setupUi(this);
	sortButtonGroup = new QButtonGroup;
	sortButtonGroup->addButton(ui->idradioButton,0);
	sortButtonGroup->addButton(ui->graderadioButton,1);
	ui->idradioButton->setChecked(true);
	//out<<name<<" "<<number<<" "<<age<<" "<<gender<<" "<<tel<<" "<<bir<<" "<<address<<" "<<grade<<"\n";
	ui->tableWidget->setColumnCount(8);
	QStringList headerLabels;
	headerLabels<<tr("姓名")<<tr("学号")<<tr("年龄")<<tr("性别")<<tr("电话")<<tr("生日")<<tr("地址")<<tr("成绩");
	ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->setRowCount(1);
}

SortWidget::~SortWidget() {
	delete ui;
}

void SortWidget::on_returnButton_clicked() {
	emit display(0);
}

void SortWidget::on_sortpushButton_clicked() {
	ui->tableWidget->clearContents();
	int sortTag = sortButtonGroup->checkedId();
	QVector<stuinfo> allStuInfo;
	if(!getStuInfo(allStuInfo))
		return;
	if(allStuInfo.empty()) {
		QMessageBox::about(NULL,"反馈","没有学生信息");
		return;
	}
	switch (sortTag) {
		case 0://学号
			std::sort(allStuInfo.begin(),allStuInfo.end(),cmp_number);
			break;
		case 1://成绩
			std::sort(allStuInfo.begin(),allStuInfo.end(),cmp_score);
			break;
		default:
			break;
	}
	ui->tableWidget->setRowCount(allStuInfo.size());

	for(int i = 0 ; i < allStuInfo.size() ; i++ ) {
		ui->tableWidget->setItem(i,0,new QTableWidgetItem(allStuInfo[i].getname()));
		ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(allStuInfo[i].getnumber())));
		ui->tableWidget->setItem(i,2,new QTableWidgetItem(allStuInfo[i].getage()));
		ui->tableWidget->setItem(i,3,new QTableWidgetItem(allStuInfo[i].getgender()));
		ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(allStuInfo[i].gettel())));
		ui->tableWidget->setItem(i,5,new QTableWidgetItem(allStuInfo[i].getbir()));
		ui->tableWidget->setItem(i,6,new QTableWidgetItem(allStuInfo[i].getaddress()));
		ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(allStuInfo[i].getscore())));
	}
}
