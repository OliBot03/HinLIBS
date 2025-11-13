#include "checkOutService.h"


string checkOutService::checkOutItem(int patronId, int itemId) {
    // check if both patron and item exist
    Patron* p1 = patrons.getPatronById(patronId);
    Item* i1 = catalogue.getItemById(itemId);
    if (p1 == nullptr) return ("CHECKOUT ERROR: Patron with given ID doesn't exist!");
    if (i1 == nullptr) return ("CHECKOUT ERROR: Item with given ID doesn't exist!");

    //check if item already checked out
    if (i1->isCheckedOut()) {
        cout << "Item is already checked out! "; 
        //*********TO DO: OFFER PATRON OPTION TO PLACE HOLD IF THEY WANT TO **********/

        // if patron has hold on item AND is first on hold queue, allow checkout

        // if patron doesn't have active hold, ask if they want to place one.
    }

    //check patron active loans < 3
    if (p1->getActiveLoanCount() >= 3) return ("CHECKOUT ERROR: Patron already has 3 active loans!!");

    // create Loan, set item to checked out, update patron loan count
    Loan& newLoan = loans.addLoan(p1->getPatronId(), i1->getItemId(), 14); // make loan for 14 days

    i1->markCheckedOut();
    p1->addActiveLoan();


    const std::time_t due = newLoan.getDueAt();  // needs getter added earlier
    return std::string("CHECKOUT SUCCESS: ")
         + i1->getTitle() + " | Due: " + ymd(due)
         + " | Days remaining: " + std::to_string(days_remaining(due));

}



