#ifndef STUMENUWIDGET_H
#define STUMENUWIDGET_H

#include <QDialog>

#include <QStackedLayout>
#include "addstudentwidget.h"
#include "findwidget.h"
#include "modifywidget.h"
#include "sortwidget.h"
namespace Ui {
	class stumenuwidget;
}

class stumenuwidget : public QDialog {
		Q_OBJECT

	public:
		explicit stumenuwidget(QWidget *parent = nullptr);
		~stumenuwidget();


	signals:
        void display(int number);//作为stackLayout切换页面的信号

	private slots:
		void on_findButton_clicked();

		void on_sortButton_clicked();

		void on_exitButton_clicked();

	private:
		Ui::stumenuwidget *ui;
};

#endif // STUMENUWIDGET_H
