#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountWindow(QWidget *parent = nullptr, QString username = "");
    ~AccountWindow();
    void setUsername(const QString &username);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AccountWindow *ui;
    QString username;
};

#endif // ACCOUNTWINDOW_H
