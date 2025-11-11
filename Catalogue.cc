#include <string>
#include <iostream>
#include <memory>
#include "Catalogue.h"


Catalogue::Catalogue(){
    addItem(std::make_unique<FictionBook>("F1", "Author A", "111"));
    addItem(std::make_unique<FictionBook>("F2", "Author B", "112"));
    addItem(std::make_unique<FictionBook>("F3", "Author C", "113"));
    addItem(std::make_unique<FictionBook>("F4", "Author D", "114"));
    addItem(std::make_unique<FictionBook>("F5", "Author E", "115"));

    addItem(std::make_unique<NonFictionBook>("NF1","Author A","211","000.01"));
    addItem(std::make_unique<NonFictionBook>("NF2","Author B","212","100.02"));
    addItem(std::make_unique<NonFictionBook>("NF3","Author C","213","200.03"));
    addItem(std::make_unique<NonFictionBook>("NF4","Author D","214","300.04"));
    addItem(std::make_unique<NonFictionBook>("NF5","Author E","215","400.05"));

    addItem(std::make_unique<Magazine>("M1","Editor A","1","Jan 1999"));
    addItem(std::make_unique<Magazine>("M2","Editor B","2","Feb 1991"));
    addItem(std::make_unique<Magazine>("M3","Editor C","3","Mar 1992"));

    addItem(std::make_unique<Movie>("MO1","Director A","Horror","R"));
    addItem(std::make_unique<Movie>("MO2","Director B","Fantasy","PG-13"));
    addItem(std::make_unique<Movie>("MO3","Director C","Action","PG"));

    addItem(std::make_unique<VideoGame>("VG1","Studio A","Action","PG"));
    addItem(std::make_unique<VideoGame>("VG2","Studio B","Rogue-lite","PG-13"));
    addItem(std::make_unique<VideoGame>("VG3","Studio C","Horror","R"));
    addItem(std::make_unique<VideoGame>("VG4","Studio D","FPS","R"));
}

void Catalogue::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void Catalogue::printItems() {
    for(size_t i = 0; i < items.size(); i++) {
        items.at(i)->print(cout);
        cout << endl;
    }
        
}
