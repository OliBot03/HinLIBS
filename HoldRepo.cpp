#include "HoldRepo.h"

Hold& HoldRepo::addHold(int patronId, int itemId) {
    unique_ptr<Hold> H1 = std::make_unique<Hold>(patronId, itemId);
    holds.push_back(std::move(H1));
    return *holds.back();
}

Hold* HoldRepo::getHoldById(int id) {
    for (size_t i = 0; i < holds.size(); i++) {
        if (holds.at(i)->getHoldId() == id)
            return holds.at(i).get();
    }
    // no hold found w given id
    return nullptr;
}

void HoldRepo::printHoldById(int id) {
    Hold* H1 = getHoldById(id);
    if (H1)
        H1->printHold();
    else {
        // no hold found send msg
        cout << "Hold with ID " << id << " not found." << endl;
    }
}

vector<Hold*> HoldRepo::getHoldsByPatron(int patronId) {
    vector<Hold*> patronHolds;

    for (size_t i = 0; i < holds.size(); i++) {
        if (holds.at(i)->getPatronId() == patronId) {
            patronHolds.push_back(holds.at(i).get());
        }
        // maybe check size in case it's empty
    }

    return patronHolds;
}

vector<Hold*> HoldRepo::getHoldsByItem(int itemId) {
    vector<Hold*> itemHolds;

    for (size_t i = 0; i < holds.size(); i++) {
        if (holds.at(i)->getItemId() == itemId) {
            itemHolds.push_back(holds.at(i).get());
        }
        // maybe check size in case it's empty
    }

    return itemHolds;
}

bool HoldRepo::removeHold(int holdId) {
    for (size_t i = 0; i < holds.size(); i++) {
        if (holds.at(i)->getHoldId() == holdId) {
            holds.erase(holds.begin() + i);
            return true;
        }
    }
    return false;
}