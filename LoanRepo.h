#ifndef LOANREPO_H
#define LOANREPO_H
#include "Loan.h"
#include <vector>

class LoanRepo {

    public:
        Loan& addLoan(int, int, int); //(patronId, itemId, LengthInDays). Returns ref to newly added loan
        Loan* getLoanById(int id);
        void printLoanById(int id);
        vector<Loan*> getLoanByPatron(int id); // i don't return unique_ptrs cause only repo should have ownership
        Loan* getLoanByItem(int id);
        bool markReturned(int, std::time_t);    //(itemId, date returned)
        

    private:
        vector<unique_ptr<Loan>> loans;

};

#endif
