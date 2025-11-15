#include "accountitemui.h"
#include "ui_accountitemui.h"
#include <sstream>

accountitemui::accountitemui(QWidget *parent, Item* i) :
    QWidget(parent),
    ui(new Ui::accountitemui)
{
    ui->setupUi(this);
    std::ostringstream oss;
    i->print(oss);
    currentItem = i;
    QString mData = QString::fromStdString(oss.str());

    ui->label->setText(mData);
}

accountitemui::~accountitemui()
{
    delete ui;
}

void accountitemui::on_exit_clicked()
{
    this->close();
}


void accountitemui::on_CheckIn_clicked()
{
    //check In functionality
}

