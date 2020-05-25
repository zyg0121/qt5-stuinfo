#include "stumenuwidget.h"
#include "ui_stumenuwidget.h"

stumenuwidget::stumenuwidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::stumenuwidget) {
	ui->setupUi(this);
}

stumenuwidget::~stumenuwidget() {
	delete ui;
}

void stumenuwidget::on_findButton_clicked() {
	emit display(1);
}

void stumenuwidget::on_sortButton_clicked() {
	emit display(2);
}

void stumenuwidget::on_exitButton_clicked() {
	QApplication::exit();
}
