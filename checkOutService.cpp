#include "checkOutService.h"

CheckoutResult checkOutService::checkOutItem(int patronId, int itemId, HoldRepo& h) {
    // check if both patron and item exist
    Patron* p1 = patrons.getPatronById(patronId);
    Item* i1 = catalogue.getItemById(itemId);
    cout<<"Checkout initiated by PatronID:"<<patronId<<endl;
    if (p1 == nullptr) return CheckoutResult::PatronDoesNotExist;
    if (i1 == nullptr) return CheckoutResult::ItemDoesNotExist;

    cout<<"Attempting to check out: "<<i1->getTitle()<<endl;

    //check if item already checked out
    if (i1->isCheckedOut()) {
        cout << "Item is already checked out! "; 
        //Temporary:
        return CheckoutResult::AlreadyCheckedOut;
        //*********TO DO: OFFER PATRON OPTION TO PLACE HOLD IF THEY WANT TO *********

        // if patron has hold on item AND is first on hold queue, allow checkout

        // if patron doesn't have active hold, ask if they want to place one.
    }

    //check patron active loans < 3
    if (p1->getActiveLoanCount() >= 3) return CheckoutResult::TooManyLoans;

    // create Loan, set item to checked out, update patron loan count

    if (i1->isCheckedOut() == false){
        if (holds.getHoldsByItem(i1->getItemId()).empty()){
            Loan& newLoan = loans.addLoan(p1->getPatronId(), i1->getItemId(), 14); // make loan for 14 days

            i1->markCheckedOut();
            p1->addActiveLoan(i1->getItemId());


            const std::time_t due = newLoan.getDueAt();  // needs getter added earlier
            return CheckoutResult::Success;
        }else{
           Hold* nextHold = holds.getHoldsByItem(i1->getItemId())[0];
           if (nextHold->getPatronId() == p1->getPatronId()){
               Loan& newLoan = loans.addLoan(p1->getPatronId(), i1->getItemId(), 14); // make loan for 14 days

               i1->markCheckedOut();
               p1->addActiveLoan(i1->getItemId());
               p1->removeActiveLoan(i1->getItemId());


               const std::time_t due = newLoan.getDueAt();  // needs getter added earlier
               return CheckoutResult::Success;
           }else{
               return CheckoutResult::ItemOnHold;
           }
        }
    }

         //***********TO DO: Figure out way to return loan details as well on a success?
         //+ i1->getTitle() + " | Due: " + ymd(due)
         //+ " | Days remaining: " + std::to_string(days_remaining(due));

}



