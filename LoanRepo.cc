#include "LoanRepo.h"


Loan& LoanRepo::addLoan(int patronId, int itemId, int lengthInDays) {
    unique_ptr<Loan> L1 = std::make_unique<Loan>(patronId, itemId, lengthInDays);
    loans.push_back(std::move(L1));
    return *loans.back();
}

Loan* LoanRepo::getLoanById(int id) {
    for (size_t i=0; i < loans.size(); i++) {
        if (loans.at(i)->getLoanId() == id && loans.at(i)->isActive())
            return loans.at(i).get();
    }
    // no loan found w given id
    return nullptr;
}

void LoanRepo::printLoanById(int id) {
    Loan* L1 = getLoanById(id);
    if (L1)
        L1->printLoan();
    else {
        // no loan found send msg
    }

}

vector<Loan*> LoanRepo::getLoanByPatron(int patronId) {
    vector<Loan*> v1;

    for (size_t i=0; i < loans.size(); i++) {
        if (loans.at(i)->getPatronId() == patronId && loans.at(i)->isActive()) {
            v1.push_back(loans.at(i).get());
        }
        //maybe check size incase its empty? same for getloansbyItem below
    }

    return v1;
}

Loan* LoanRepo::getLoanByItem(int itemId){

    for (size_t i=0; i < loans.size(); i++) {
        if (loans.at(i)->getItemId() == itemId && loans.at(i)->isActive()) {
            return loans.at(i).get();
        }
        //item has no loan attached to it
    }
    return nullptr;
}

// TO DO 
bool LoanRepo::markReturned(int itemId, std::time_t retDate) {
    Loan* L1 = getLoanByItem(itemId);
    if (!(L1)) return false; // no active loan for this item, cant mark it returned

    L1->setReturned(retDate); 
    return true;
}