#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QButtonGroup>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "stuinfo.h"

namespace Ui {
	class SortWidget;
}

class SortWidget : public QDialog {
		Q_OBJECT

	public:
		explicit SortWidget(QWidget *parent = nullptr);
		~SortWidget();
	signals:
		void display(int number);
	private slots:
		void on_returnButton_clicked();

		void on_sortpushButton_clicked();

	private:
		Ui::SortWidget *ui;
		QButtonGroup *sortButtonGroup;
};

#endif // SORTWIDGET_H
