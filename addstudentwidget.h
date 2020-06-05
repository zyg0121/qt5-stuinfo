#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QString>

namespace Ui {
	class AddStudentWidget;
}

class AddStudentWidget : public QDialog {
		Q_OBJECT

	public:
		explicit AddStudentWidget(QWidget *parent = nullptr);
		~AddStudentWidget();
	signals:
        void display(int number);//作为stackLayout切换页面的信号

	private slots:
		void on_returnButton_clicked();

		void on_addButton_clicked();

	private:
		Ui::AddStudentWidget *ui;
};

#endif // ADDSTUDENTWIDGET_H
