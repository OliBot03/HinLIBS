#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QMainWindow>
#include "UserDefs.h"
#include "AccountService.h"

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountWindow(QWidget *parent = nullptr, Patron *p = nullptr);
    ~AccountWindow();
    void setUsername(const QString &username);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AccountWindow *ui;
    QString username;
    Patron  *currentUser;
};

#endif // ACCOUNTWINDOW_H
