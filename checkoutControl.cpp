#include "checkoutControl.h"

CheckoutResult checkoutControl::attemptCheckout(Item* item, Patron* p){
    if (item->isCheckedOut())
        return CheckoutResult::AlreadyCheckedOut;
    if (p->getActiveLoanCount() >= 3) // Three or more active loans not allowed
        return CheckoutResult::TooManyLoans;
    p->addActiveLoan(item->getItemId());
    item->markCheckedOut();
    return CheckoutResult::Success;
}
