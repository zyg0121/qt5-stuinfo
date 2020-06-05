#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QDialog>

#include "adminwidget.h"
#include "stuwidget.h"

namespace Ui {
	class MainWidget;
}

class MainWidget : public QDialog {
		Q_OBJECT

	public:
		explicit MainWidget(QWidget *parent = nullptr);
		~MainWidget();

	private slots:
		void on_loginpushButton_clicked();

		void on_stupushButton_clicked();

	private:
        Ui::MainWidget *ui;//主菜单界面

        adminwidget *admin_ui;//管理员菜单界面
        stuwidget *stu_ui;//学生菜单界面
};

#endif // MAINWIDGET_H
