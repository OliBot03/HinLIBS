#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(Catalogue& c, PatronRepo& p, LoanRepo& l,QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
     catalogue (c),
     currentUser(nullptr),
     patrons (p),
     loans  (l)
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
    acc = new AccountWindow(this, currentUser);
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



