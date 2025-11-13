#include "checkoutControl.h"

CheckoutResult checkoutControl::attemptCheckout(Item* item, Patron* p){
    if (item->isCheckedOut())
        return CheckoutResult::AlreadyCheckedOut;
    if (p->getActiveLoanCount() == 3)
        return CheckoutResult::TooManyLoans;
    p->addActiveLoan(item);
    item->markCheckedOut();
    return CheckoutResult::Success;
}
