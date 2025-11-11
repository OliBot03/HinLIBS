#include "accountwindow.h"
#include "ui_accountwindow.h"

AccountWindow::AccountWindow(QWidget *parent, QString u) :
    QMainWindow(parent),
    ui(new Ui::AccountWindow)
{
    username = u;
    ui->setupUi(this);
    ui->label->setText(username + " - Account Details");
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
