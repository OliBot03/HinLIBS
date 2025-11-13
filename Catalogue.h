#ifndef CATALOGUE_H
#define CATALOGUE_H
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "ObjectDefs.h"
#include "UserDefs.h"
using namespace std;


class Catalogue {
    public:
        Catalogue();
        void addItem(std::unique_ptr<Item>);
        Item* getItemById(int id);    
        void printItemById(int id);    
        void printItems();

        

    private:
        vector<unique_ptr<Item>> items;


};

#endif 
