#include "catalogueitemui.h"
#include "ui_catalogueitemui.h"

CatalogueItemUI::CatalogueItemUI(QWidget *parent, Item i) :
    QWidget(parent),
    ui(new Ui::CatalogueItemUI)
{
    std::ostringstream oss;
    i.print(oss);
    QString mData = QString::fromStdString(oss.str());

    ui->setupUi(this);
    ui->metaData->setText(mData);
}

CatalogueItemUI::~CatalogueItemUI()
{
    delete ui;
}

void CatalogueItemUI::on_checkin_clicked()
{
    //run check in script
    // change status label based on success/failure
}


void CatalogueItemUI::on_checkout_clicked()
{
    //run check out script
    // change status label based on success/failure
}


void CatalogueItemUI::on_exit_clicked()
{
    this->close();
}


void CatalogueItemUI::on_placeHold_clicked()
{
    //run place hold script
    // change status label based on success/failure
}

