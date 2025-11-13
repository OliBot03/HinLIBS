#ifndef LOAN_H
#define LOAN_H

#include "Catalogue.h"
#include "UserRepo.h"
#include "timeUtils.h"


class Loan {

    public:
        Loan(int pId, int itId, int loanLength) : loanId(nextLoanId++), patronId(pId), itemId(itId), returnedDate(0) {
            borrowedAt = now_epoch();
            dueAt = days_from_now(loanLength); // later have this loan length set by some sysConfig file or sum
        }

        int getLoanId() const {return loanId;}
        int getPatronId() const {return patronId;}
        int getItemId() const {return itemId;}  
        std::time_t getDueAt() const { return dueAt; }
        std::time_t getBorrowedAt() const { return borrowedAt; }
        bool isActive() const {return (returnedDate == 0);} 
        // I'm not gonna delete loans (i feel like that's part of admin cleanup + it's nice to keep past queries)
            // -> instead I'm just marking loans as active if they don't have a return time.
        void setReturned(std::time_t when) { returnedDate = when; }

        void printLoan() const {
            cout << "ID: " << loanId << ", Patron ID: " << patronId << ", Item ID: " << itemId << ", Borrow Date: " << borrowedAt
                << ", Due Date: " << dueAt << (returnedDate ? ", Returned: " + std::to_string(returnedDate) : ", Returned: Active Loan!") << endl;
        }

        void printLoanSimplified() const {
            
        }
        
        
    private:
        inline static int nextLoanId = 3001;
        int loanId;
        int patronId;
        int itemId;
        std::time_t borrowedAt;
        std::time_t dueAt;
        std::time_t returnedDate;


};

#endif