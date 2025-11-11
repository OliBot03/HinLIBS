#ifndef CATALOGUE_H
#define CATALOGUE_H
#include <string>
#include <iostream>
#include <memory>
#include "ObjectDefs.h"
#include "UserDefs.h"


class Catalogue {
    public:
        Catalogue();
        void addItem(std::unique_ptr<Item>);
        void printItems();

    private:
        vector<unique_ptr<Item>> items;


};

#endif 
