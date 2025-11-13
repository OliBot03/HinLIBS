#include "AccountService.h"


void AccountService::displayActiveLoans(int patronId) {
    vector<Loan*> activeLoans = loans.getLoanByPatron(patronId);  

    if (activeLoans.empty()) {
        std::cout << "Patron has no active loans!\n"; 
        return;
    }

    std::cout << "Active Loans:\n\n";
    for (size_t i = 0; i < activeLoans.size(); i++) {
        Item* it = catalogue.getItemById(activeLoans.at(i)->getItemId());   // item might be null in edge cases
        const std::string title = it ? it->getTitle() : "(unknown title)";
        const std::time_t due =activeLoans.at(i)->getDueAt();

        //title, due date (YYYY-MM-DD), days remaining
        std::cout << "• " << title
                  << " | Due: " << ymd(due)
                  << " | Days remaining: " << days_remaining(due)
                  << "\n";
    }
}