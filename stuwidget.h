#ifndef STUWIDGET_H
#define STUWIDGET_H

#include <QDialog>

#include <QDialog>
#include <QStackedLayout>
#include "stumenuwidget.h"
#include "findwidget.h"
#include "sortwidget.h"

namespace Ui {
	class stuwidget;
}

class stuwidget : public QDialog {
		Q_OBJECT

	public:
		explicit stuwidget(QWidget *parent = nullptr);
		~stuwidget();

	private:
		Ui::stuwidget *ui;

		stumenuwidget *stuMenuwidget;//菜单窗口
		FindWidget *findWidget;    //查询窗口
		SortWidget *sortwidget;        //排序窗口
		QStackedLayout *stackLayout;   //QStackedLayout布局
};

#endif // STUWIDGET_H
