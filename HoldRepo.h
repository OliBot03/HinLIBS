#ifndef HOLDREPO_H
#define HOLDREPO_H

#include "Hold.h"
#include <vector>
#include <memory>

class HoldRepo {

    public:
        Hold& addHold(int, int); //(patronId, itemId). Returns ref to newly added hold
        Hold* getHoldById(int id);
        void printHoldById(int id);
        vector<Hold*> getHoldsByPatron(int id);
        vector<Hold*> getHoldsByItem(int id);
        bool removeHold(int holdId);

    private:
        vector<unique_ptr<Hold>> holds;

};

#endif