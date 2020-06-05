#ifndef DELWIDGET_H
#define DELWIDGET_H

#include <QDialog>

namespace Ui {
	class DelWidget;
}

class DelWidget : public QDialog {
		Q_OBJECT

	public:
		explicit DelWidget(QWidget *parent = nullptr);
		~DelWidget();

	signals:
        void display(int number);//作为stackLayout切换页面的信号

	private slots:
		void on_deletepushButton_clicked();

		void on_returnButton_clicked();

	private:
		Ui::DelWidget *ui;
};

#endif // DELWIDGET_H
