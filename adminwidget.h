#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QDialog>

#include <QStackedLayout>
#include "adminmenuwidget.h"
#include "addstudentwidget.h"
#include "findwidget.h"
#include "modifywidget.h"
#include "sortwidget.h"
#include "delwidget.h"
namespace Ui {
	class adminwidget;
}

class adminwidget : public QDialog {
		Q_OBJECT

	public:
		explicit adminwidget(QWidget *parent = nullptr);
		~adminwidget();

	private:
		Ui::adminwidget *ui;

		MenuWidget *menuwidget;//菜单窗口
		AddStudentWidget *addstudentwidget;   //添加学生窗口
		FindWidget *findWidget;    //查询窗口
		DelWidget *delWidget;  //删除窗口
		ModifyWidget *modifywidget;    //修改窗口
		SortWidget *sortwidget;        //排序窗口
		QStackedLayout *stackLayout;   //QStackedLayout布局
};

#endif // ADMINWIDGET_H
