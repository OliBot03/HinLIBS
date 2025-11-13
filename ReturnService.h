#ifndef RETURNSERVICE_H
#define RETURNSERVICE_H

#include "LoanRepo.h"
#include "UserRepo.h"
#include "Catalogue.h"

class returnService {

    public:
        returnService(Catalogue& cat, PatronRepo& user, LoanRepo& loan) :  catalogue(cat), patrons(user), loans(loan) {} 
        string returnItem(int, int);


    private:
        Catalogue& catalogue;
        PatronRepo& patrons;
        LoanRepo& loans;



};


#endif
