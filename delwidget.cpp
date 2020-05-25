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
	pHead.InputStudent();
	long long number = ui->idlineEdit->text().toLongLong();
	pHead.DeleteStudent(number);
	pHead.OutputStudent();
	ui->idlineEdit->clear();
}

void DelWidget::on_returnButton_clicked() {
	emit display(0);
}
