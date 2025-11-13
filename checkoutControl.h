#ifndef CHECKOUTCONTROL_H
#define CHECKOUTCONTROL_H
#include "UserDefs.h"
#include "ObjectDefs.h"

enum class CheckoutResult {
    Success,
    AlreadyCheckedOut,
    TooManyLoans
};

class checkoutControl {
    public:
        CheckoutResult attemptCheckout(Item* item, Patron* patron);
};

#endif // CHECKOUTCONTROL_H
