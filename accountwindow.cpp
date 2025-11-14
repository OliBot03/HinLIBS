#include "accountwindow.h"
#include "ui_accountwindow.h"
#include <sstream>


AccountWindow::AccountWindow(QWidget *parent, Patron *u, HoldRepo *h, Catalogue *cat) :
    QMainWindow(parent),
    ui(new Ui::AccountWindow),
    currentUser(u),
    holds(h),
    catalogue(cat)
{
    ui->setupUi(this);
    ui->label->setText("Account Details");
    std::ostringstream oss;
    /* OLD IMPLEMENTATION 
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

/* OLD IMPLEMENTATION WITHOUT QUEUE POSITION
------------------------------------------------
    Builds hold list with similar logic to loans list 
    if (currentUser && holds) {
        auto myHolds = holds->getHoldsByPatron(currentUser->getPatronId());  // Specific Patron's holds
        for (Hold *hold : myHolds) {
            QString temp = QString::number(hold->getItemId());
            QListWidgetItem *listItem = new QListWidgetItem(temp);
            listItem->setData(Qt::UserRole, hold->getItemId());
            ui->listWidget_2->addItem(listItem);
        }
        ui->listWidget_2->update();
    }
}
*/
   if (u) { // Prints only if user is valid
        u->printPatron(oss);
    }
    QString mData = QString::fromStdString(oss.str());
    ui->AccountDetails->setText(mData);

    // Loans list - Title (ID: XXXX)
    if (currentUser && catalogue) {
        for (Loan* loan : currentUser->getLoans()) {
            Item* item = catalogue->getItemById(loan->getItemId());

            QString text;
            if (item) {
                text = QString("%1 (ID: %2)")
                           .arg(QString::fromStdString(item->getTitle()))
                           .arg(item->getItemId());
            } else {
                // fallback if item is missing display only ID
                text = QString("Item ID: %1").arg(loan->getItemId());
            }

            QListWidgetItem *listItem = new QListWidgetItem(text);
            listItem->setData(Qt::UserRole, loan->getItemId());
            ui->listWidget->addItem(listItem);
        }
        ui->listWidget->update();
    }

    // Holds list - Title (ID: XXXX) - Position in hold queue: X
    if (currentUser && holds && catalogue) {
        auto myHolds = holds->getHoldsByPatron(currentUser->getPatronId());

        for (Hold *hold : myHolds) {
            // gets queue for the specific item init numb and increments position
            auto itemQueue = holds->getHoldsByItem(hold->getItemId());
            int position = 1;
            for (size_t i = 0; i < itemQueue.size(); ++i) {
                if (itemQueue[i]->getHoldId() == hold->getHoldId()) {
                    position = static_cast<int>(i) + 1;
                    break;
                }
            }

            Item* item = catalogue->getItemById(hold->getItemId());
            QString title = item
                    ? QString::fromStdString(item->getTitle())
                    : QString("Unknown item");

            QString temp = QString("%1 (ID: %2)  -  Position in hold queue: %3")
                               .arg(title)
                               .arg(hold->getItemId())
                               .arg(position);

            QListWidgetItem *listItem = new QListWidgetItem(temp);
            listItem->setData(Qt::UserRole, hold->getItemId());
            ui->listWidget_2->addItem(listItem);
        }
        ui->listWidget_2->update();
    }
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

void AccountWindow::on_openLoan_clicked()
{
    if (ui->listWidget->currentItem() != nullptr){
        int ID = ui->listWidget->currentItem()->data(Qt::UserRole).toInt();
        Item* currentItem = catalogue->getItemById(ID);

        accountitemui* AIUI = new accountitemui(this, currentItem);
        AIUI->show();
    }
}


void AccountWindow::on_openHold_clicked()
{
    if (ui->listWidget_2->currentItem() != nullptr){
        int ID = ui->listWidget_2->currentItem()->data(Qt::UserRole).toInt();
        Item* currentItem = catalogue->getItemById(ID);

        holditemui* HIUI = new holditemui(this, currentItem);
        HIUI->show();
    }
}

