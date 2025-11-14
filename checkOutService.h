#ifndef CHECKOUTSERVICE_H
#define CHECKOUTSERVICE_H

#include "LoanRepo.h"
#include "UserRepo.h"
#include "Catalogue.h"

enum class CheckoutResult {
    Success,
    AlreadyCheckedOut,
    TooManyLoans,
    PatronDoesNotExist,
    ItemDoesNotExist
};

class checkOutService {

    public:
        checkOutService(Catalogue& cat, PatronRepo& user, LoanRepo& loan) : catalogue(cat), patrons(user), loans(loan) {}

        // TO-DO: format the return of this better?
        CheckoutResult checkOutItem(int, int); //should return either loan details (due date yyyy-mm-dd) or reason for failiure



    private:
        Catalogue& catalogue;
        PatronRepo& patrons;
        LoanRepo& loans;
};
#endif
