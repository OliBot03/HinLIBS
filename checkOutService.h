#ifndef CHECKOUTSERVICE_H
#define CHECKOUTSERVICE_H

#include "LoanRepo.h"
#include "UserRepo.h"
#include "Catalogue.h"
#include "HoldRepo.h"

enum class CheckoutResult {
    Success,
    AlreadyCheckedOut,
    TooManyLoans,
    PatronDoesNotExist,
    ItemDoesNotExist,
    ItemOnHold
};

class checkOutService {

    public:
        checkOutService(Catalogue& cat, PatronRepo& user, LoanRepo& loan, HoldRepo& h) : catalogue(cat), patrons(user), loans(loan), holds(h) {}

        // TO-DO: format the return of this better?
        CheckoutResult checkOutItem(int, int, HoldRepo& h); //should return either loan details (due date yyyy-mm-dd) or reason for failiure



    private:
        Catalogue& catalogue;
        PatronRepo& patrons;
        LoanRepo& loans;
        HoldRepo& holds;
};
#endif
