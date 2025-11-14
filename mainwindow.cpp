#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(Catalogue& c, PatronRepo& p, LoanRepo& l, HoldRepo& h, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      catalogue(c),
      patrons(p),
      loans(l),
      holds(h),
      currentUser(nullptr)
{
    ui->setupUi(this);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::quit);
    connect(ui->actionSign_In, &QAction::triggered, this, &MainWindow::login);
    connect(ui->actionSign_Out, &QAction::triggered, this, &MainWindow::logout);
    connect(ui->actionView, &QAction::triggered, this, &MainWindow::view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit(){
    this->close();
}

void MainWindow::login(){
    l = new loginUI(this);
    connect(l, &loginUI::loginAttempt, this, &MainWindow::handleLoginAttempt);
    l->show();
}

void MainWindow::view(){
    acc = new AccountWindow(this, currentUser, &holds, &catalogue);
    acc->show();
}


void MainWindow::loginSuccessHandler(Patron* patron){
    ui->actionSign_In->setVisible(false);
    ui->actionView->setVisible(true);
    l->close();
}


void MainWindow::logout(){
    ui->actionSign_In->setVisible(true);
    ui->actionView->setVisible(false);
    currentUser = nullptr;
}

void MainWindow::loadCatalogue(){
    vector<int> itemids = catalogue.getItemIds();
    for (size_t i = 0;  i < itemids.size(); i++) {

        QString temp = QString::fromStdString(catalogue.getItemById(itemids[i])->getTitle());
        QListWidgetItem *listItem = new QListWidgetItem(temp);
        listItem->setData(Qt::UserRole, catalogue.getItemById(itemids[i])->getItemId());
        ui->CatalogueUI->addItem(listItem);
    }
    ui->CatalogueUI->update();
}


void MainWindow::on_pushButton_clicked()
{
    int ID = ui->CatalogueUI->currentItem()->data(Qt::UserRole).toInt();
    Item* currentItem = catalogue.getItemById(ID);
    CatalogueItemUI *CIUI;
    CIUI = new CatalogueItemUI(this,currentItem);
    connect(CIUI, &CatalogueItemUI::checkoutInitiated, this, &MainWindow::handleCheckout);
    connect(CIUI, &CatalogueItemUI::holdInitiated, this, &MainWindow::handlePlaceHold);
    CIUI->show();
}

void MainWindow::handleLoginAttempt(const QString& username,  const QString& password){
    Patron* p = patrons.getPatronByUsername(username.toStdString());
    //Check the patron exists
    if (!p){
         QMessageBox::warning(this, "LoginFailed", "That user  does not exist.");
         return;
    }

    //Passwordd check
    if (p->validateLogin(password.toStdString())){
        currentUser = p;
        loginSuccessHandler(p);
    } else {
        QMessageBox::warning(this, "LoginFailed", "Incorrect password.");
    }
}

void MainWindow::handleCheckout(Item* item){
    checkoutControl c;
    if (currentUser == nullptr){
        QMessageBox::warning(this, "Checkout Error", "You are not logged in.");
    }else{
        CheckoutResult result = c.attemptCheckout(item, currentUser);
        switch (result) {
        case CheckoutResult::TooManyLoans:
            QMessageBox::warning(this, "Checkout Error", "You have too many active loans.");
            break;
        case CheckoutResult::AlreadyCheckedOut:
            QMessageBox::warning(this, "Checkout Error", "Item already checked out.");
            break;
        default:
            QMessageBox::information(this, "Success", "Item checked out!");
            break;
        }
    }
}

void MainWindow::handlePlaceHold(Item* item)
{
    if (!currentUser) {
        QMessageBox::warning(this, "Hold Error", "You must be signed in to place a hold.");
        return;
    }

    if (!item) {
        QMessageBox::warning(this, "Hold Error", "No item selected.");
        return;
    }
 //   const bool atLoanLimit = (currentUser->getActiveLoanCount() >= 3);
    // Holds only allowed if item is currently checked out
    if (!item->isCheckedOut()) {
        QMessageBox::warning(
            this,
            "Hold Error",
            "This item is currently available.\n"
            "Holds can only be placed on items that are checked out."
        );
        return;
    }

    // Prevents a place a hold on an item that patrons haev already checked out
    for (Loan* loan : currentUser->getLoans()) {
        if (loan->getItemId() == item->getItemId() && loan->isActive()) {
            QMessageBox::warning(
                this,
                "Hold",
                "You already have this item checked out."
            );
            return;
        }
    }

    // Prevent duplicate holds by the same patron on the same item
    auto itemHolds = holds.getHoldsByItem(item->getItemId());
    for (Hold* h : itemHolds) {
        if (h->getPatronId() == currentUser->getPatronId()) {
            QMessageBox::warning(
                this,
                "Hold",
                "You already have a hold on this item."
            );
            return;
        }
    }

    // Creates hold
    Hold& h = holds.addHold(currentUser->getPatronId(), item->getItemId());

    // Compute Patron User's position in the queue for this item
    auto queue = holds.getHoldsByItem(item->getItemId());
    int position = 1;
    for (size_t i = 0; i < queue.size(); ++i) {
        if (queue[i]->getHoldId() == h.getHoldId()) {
            position = static_cast<int>(i) + 1;  // increment
            break;
        }
    }

    QString msg = QString("Hold placed.\n\n"
                          "Hold ID: %1\n"
                          "Item: %2\n"
                          "Placed: %3\n"
                          "Position in hold queue: %4")
                      .arg(h.getHoldId())
                      .arg(QString::fromStdString(item->getTitle()))
                      .arg(QString::fromStdString(ymd(h.getPlacedAt())))
                      .arg(position);

    QMessageBox::information(this, "Hold Placed", msg);
}
