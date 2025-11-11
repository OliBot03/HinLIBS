#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
