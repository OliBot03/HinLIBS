#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Catalogue& c, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
    , catalogue (c)
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
    l->show();
    connect(l, &loginUI::loginSuccess, this, &MainWindow::loginSuccessHandler);

}

void MainWindow::view(){
    acc->show();
}


void MainWindow::loginSuccessHandler(const QString &username){
    acc = new AccountWindow(this, username);
    ui->actionSign_In->setVisible(false);
    ui->actionView->setVisible(true);
}


void MainWindow::logout(){
    ui->actionSign_In->setVisible(true);
    ui->actionView->setVisible(false);
}

void MainWindow::loadCatalogue(){
    for (const auto& itemPtr : catalogue.getItems()) {

        QString temp = QString::fromStdString(itemPtr->getTitle());
        QListWidgetItem *listItem = new QListWidgetItem(temp);
        listItem->setData(Qt::UserRole, itemPtr->getItemId());
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
    CIUI->show();
}

