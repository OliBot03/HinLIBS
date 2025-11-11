#include "loginui.h"
#include "ui_loginui.h"

loginUI::loginUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginUI)
{
    ui->setupUi(this);
}

loginUI::~loginUI()
{
    delete ui;
}

void loginUI::on_QuitLogin_clicked()
{
    this->close();
}


void loginUI::on_loginButton_clicked()
{
    //login verifier code

    QString username = ui->Username->text();
    emit loginSuccess(username);
    this->close();

    //else login error
}

