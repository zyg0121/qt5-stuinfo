#include "adminwidget.h"
#include "ui_adminwidget.h"

adminwidget::adminwidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::adminwidget) {
	ui->setupUi(this);

	//设置stacklayout布局，声明所需窗口
	menuwidget = new MenuWidget;
	addstudentwidget = new AddStudentWidget;
	findWidget = new FindWidget;
	modifywidget = new ModifyWidget;
	sortwidget = new SortWidget;
	delWidget = new DelWidget;
	stackLayout = new QStackedLayout;

	stackLayout ->addWidget(menuwidget);
	stackLayout ->addWidget(addstudentwidget);
	stackLayout ->addWidget(findWidget);
	stackLayout ->addWidget(delWidget);
	stackLayout ->addWidget(modifywidget);
	stackLayout ->addWidget(sortwidget);

	setLayout(stackLayout);

    //connect把信号和槽进行关联
	connect(menuwidget, &MenuWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(addstudentwidget, &AddStudentWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(findWidget, &FindWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(delWidget, &DelWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(modifywidget, &ModifyWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(sortwidget, &SortWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

adminwidget::~adminwidget() {
	delete ui;
}
