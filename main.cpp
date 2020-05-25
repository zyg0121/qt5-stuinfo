#include <QApplication>

#include <QDialog>

#include <QWidget>
#include <QtGui>
#include "mainwidget.h"
#include "stuwidget.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	MainWidget w;
	w.setWindowTitle("学生信息管理系统");
	w.setWindowIcon(QIcon(":/images/logo.ico"));
	w.show();
	return app.exec();
}
