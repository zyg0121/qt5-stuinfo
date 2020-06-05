#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QDialog>

namespace Ui {
	class MenuWidget;
}

class MenuWidget : public QDialog {
		Q_OBJECT

	public:
		explicit MenuWidget(QWidget *parent = nullptr);
		~MenuWidget();

	signals:
        void display(int number);//作为stackLayout切换页面的信号

	private slots:
		void on_addButton_clicked();

		void on_findButton_clicked();

		void on_modifyButton_clicked();

		void on_sortButton_clicked();

		void on_exitButton_clicked();

		void on_delpushButton_clicked();

	private:
		Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
