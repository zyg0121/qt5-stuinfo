#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QDialog>

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include "node.h"

namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = nullptr);
    ~ModifyWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();

    void on_modifypushButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::ModifyWidget *ui;
};

#endif // MODIFYWIDGET_H
