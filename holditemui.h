#ifndef HOLDITEMUI_H
#define HOLDITEMUI_H

#include <QWidget>
#include "ObjectDefs.h"

namespace Ui {
class holditemui;
}

class holditemui : public QWidget
{
    Q_OBJECT

public:
    explicit holditemui(QWidget *parent = nullptr, Item* i = nullptr);
    ~holditemui();

private slots:
    void on_return_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::holditemui *ui;
    Item* currentItem;
};

#endif // HOLDITEMUI_H
