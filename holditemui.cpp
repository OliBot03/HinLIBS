#include "holditemui.h"
#include "ui_holditemui.h"
#include <sstream>

holditemui::holditemui(QWidget *parent, Item* i) :
    QWidget(parent),
    ui(new Ui::holditemui)
{
    ui->setupUi(this);
    std::ostringstream oss;
    i->print(oss);
    currentItem = i;
    QString mData = QString::fromStdString(oss.str());

    ui->label->setText(mData);
}

holditemui::~holditemui()
{
    delete ui;
}

void holditemui::on_return_2_clicked()
{
    this->close();
}


void holditemui::on_pushButton_clicked()
{
    //remove hold fucntionality
}

