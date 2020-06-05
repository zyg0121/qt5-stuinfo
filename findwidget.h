#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QDialog>

#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include "stuinfo.h"
#include "node.h"

namespace Ui {
	class FindWidget;
}

class FindWidget : public QDialog {
		Q_OBJECT

	public:
		explicit FindWidget(QWidget *parent = nullptr);
		~FindWidget();
	signals:
        void display(int number);//作为stackLayout切换页面的信号

	private slots:
		void on_returnButton_clicked();

		void on_pushButton_clicked();

	private:
		Ui::FindWidget *ui;
};

#endif // FINDWIDGET_H
