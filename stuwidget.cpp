#include "stuwidget.h"
#include "ui_stuwidget.h"
#include <QLabel>
stuwidget::stuwidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::stuwidget) {
	ui->setupUi(this);
	//设置stacklayout布局，声明所需窗口
	//stumenuwidget *stuMenuwidget;
	stuMenuwidget = new stumenuwidget;
	findWidget = new FindWidget;
	sortwidget = new SortWidget;
	stackLayout = new QStackedLayout;

	stackLayout ->addWidget(stuMenuwidget);
	stackLayout ->addWidget(findWidget);
	stackLayout ->addWidget(sortwidget);

	setLayout(stackLayout);

	connect(stuMenuwidget, &stumenuwidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(findWidget, &FindWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(sortwidget, &SortWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

stuwidget::~stuwidget() {
	delete ui;
}
