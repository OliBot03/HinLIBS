#include "accountwindow.h"
#include "ui_accountwindow.h"

AccountWindow::AccountWindow(QWidget *parent, Patron *u) :
    QMainWindow(parent),
    ui(new Ui::AccountWindow)
{
    currentUser = u;
    ui->setupUi(this);
    ui->label->setText("Account Details");
    std::ostringstream oss;
    u->printPatron(oss);
    QString mData = QString::fromStdString(oss.str());
    ui->AccountDetails->setText(mData);

    for (const auto& itemPtr : u->getLoans()) {

        QString temp = QString::fromStdString(std::to_string(itemPtr->getItemId()));
        QListWidgetItem *listItem = new QListWidgetItem(temp);
        listItem->setData(Qt::UserRole, itemPtr->getItemId());
        ui->listWidget->addItem(listItem);
    }
    ui->listWidget->update();
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

void AccountWindow::on_pushButton_clicked()
{
    this->close();
}

void AccountWindow::setUsername(const QString &u){
    username = u;
}
