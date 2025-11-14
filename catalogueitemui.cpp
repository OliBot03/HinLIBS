#include "catalogueitemui.h"
#include "ui_catalogueitemui.h"

CatalogueItemUI::CatalogueItemUI(QWidget *parent, Item* i) :
    QWidget(parent),
    ui(new Ui::CatalogueItemUI)
{
    item = i;
    ui->setupUi(this);
    if (i){
        std::ostringstream oss;
        i->print(oss);
        QString mData = QString::fromStdString(oss.str());
        ui->metaData->setText(mData);
    } else {
        ui->metaData->setText("No item data available.");
    }
}

CatalogueItemUI::~CatalogueItemUI()
{
    delete ui;
}

void CatalogueItemUI::on_checkout_clicked()
{
    emit(checkoutInitiated(item));
}


void CatalogueItemUI::on_exit_clicked()
{
    this->close();
}


void CatalogueItemUI::on_placeHold_clicked()
{
    //run place hold script
    // change status label based on success/failure

    emit holdInitiated(item);
}

