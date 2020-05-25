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
		Ui::MainWidget *ui;

		adminwidget *admin_ui;
		stuwidget *stu_ui;
};

#endif // MAINWIDGET_H
