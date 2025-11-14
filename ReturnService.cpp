#include "ReturnService.h"


/* Changed it to checkinControl (Not done yet)
 * string returnService::returnItem(int patronId, int itemId) {
    
    Loan* L1 = loans.getLoanByItem(itemId);

    if(!(L1)) return ("RETURN ERROR: Item provided has no active loans on it!");
    if (L1->getPatronId() != patronId) return ("RETURN ERROR: The Item is checked out by Another Patron!");

    Item* i1 = catalogue.getItemById(itemId);
    Patron* p1 = patrons.getPatronById(patronId);

    if (!i1 || !p1) return "RETURN ERROR: Bad patron or item id!";

    //using timeUtils to set return time (which will mark the loan as inactive/done)
    const std::time_t ret = now_epoch();                     
    const bool ok = loans.markReturned(itemId, ret);
    if (!ok) return "RETURN ERROR: Could not mark Item returned!";

    // mark item as available and remove it from the patron's active loan count
    i1->markAvailable();
    p1->removeActiveLoan();


    return std::string("RETURN SUCCESS: ") 
         + i1->getTitle() + " on " + ymd(ret) + ".";  
    

}*/
