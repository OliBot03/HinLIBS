#ifndef HOLD_H
#define HOLD_H

#include "timeUtils.h"
#include <iostream>
using namespace std;

class Hold {

    public:
        Hold(int pId, int itId) : holdId(nextHoldId++), patronId(pId), itemId(itId), placedAt(now_epoch()) {}

        int getHoldId() const { return holdId; }
        int getPatronId() const { return patronId; }
        int getItemId() const { return itemId; }
        std::time_t getPlacedAt() const { return placedAt; }

        void printHold() const {
            cout << "Hold ID: " << holdId << ", Patron ID: " << patronId 
                 << ", Item ID: " << itemId << ", Placed: " << ymd(placedAt) << endl;
        }

    private:
        inline static int nextHoldId = 4001;
        int holdId;
        int patronId;
        int itemId;
        std::time_t placedAt;

};

#endif