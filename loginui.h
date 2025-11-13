#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include "UserDefs.h"
namespace Ui {
class loginUI;
}

class loginUI : public QWidget
{
    Q_OBJECT

public:
    explicit loginUI(QWidget *parent = nullptr);
    ~loginUI();


signals:
    void loginAttempt(const QString& username, const QString& password);
    void loginSuccess(Patron* user);


private slots:
    void on_QuitLogin_clicked();

    void on_loginButton_clicked();


private:
    Ui::loginUI *ui;

};

#endif // LOGINUI_H
