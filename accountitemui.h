#ifndef ACCOUNTITEMUI_H
#define ACCOUNTITEMUI_H

#include <QWidget>
#include "ObjectDefs.h"

namespace Ui {
class accountitemui;
}

class accountitemui : public QWidget
{
    Q_OBJECT

public:
    explicit accountitemui(QWidget *parent = nullptr, Item* i = nullptr);
    ~accountitemui();

private slots:
    void on_exit_clicked();

    void on_CheckIn_clicked();

private:
    Ui::accountitemui *ui;
    Item* currentItem;
};

#endif // ACCOUNTITEMUI_H
