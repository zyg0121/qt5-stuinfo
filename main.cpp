#include <QApplication>

#include <QDialog>

#include <QWidget>
#include <QtGui>
#include "mainwidget.h"
#include "stuwidget.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

    MainWidget w;//创建主窗口
    w.setWindowTitle("学生信息管理系统");//设置窗口名称
    w.setWindowIcon(QIcon(":/images/logo.ico"));//设置图标
	w.show();
	return app.exec();
}
