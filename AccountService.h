#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H

#include "UserRepo.h"
#include "LoanRepo.h"
#include "Catalogue.h"

class AccountService {

    public:
        AccountService(PatronRepo& users, LoanRepo& loan, Catalogue& cat) : patrons(users), loans(loan), catalogue(cat) {}
        void displayActiveLoans(int);
        void displayActiveHolds(int);
        vector<Loan*> getActiveLoans(int patronId);


    private:
        PatronRepo& patrons;
        LoanRepo& loans;
        Catalogue& catalogue;

};


#endif
