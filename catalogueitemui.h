#ifndef CATALOGUEITEMUI_H
#define CATALOGUEITEMUI_H

#include <QWidget>
#include "ObjectDefs.h"

#include <iostream>
#include <sstream>
#include <string>

namespace Ui {
class CatalogueItemUI;
}

class CatalogueItemUI : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogueItemUI(QWidget *parent = nullptr, Item i = Item("",""));
    ~CatalogueItemUI();

private slots:
    void on_checkin_clicked();

    void on_checkout_clicked();

    void on_exit_clicked();

    void on_placeHold_clicked();

private:
    Ui::CatalogueItemUI *ui;
    string title;
    string author;
};

#endif // CATALOGUEITEMUI_H
