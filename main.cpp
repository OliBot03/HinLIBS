#include "Catalogue.h"
#include "UserRepo.h"
#include "checkOutService.h"
#include "ReturnService.h"
#include "AccountService.h"
#include "LoanRepo.h"
#include "mainwindow.h"
#include "HoldRepo.h"
#include <QApplication>

//void controlLoop(Catalogue&, PatronRepo&, checkOutService&, returnService&, AccountService&);

int main(int argc, char *argv[])
{
  PatronRepo p = PatronRepo();
  Catalogue c = Catalogue();
  LoanRepo l = LoanRepo();
  HoldRepo h = HoldRepo();
  //checkOutService checkout(c, p, loans);
  returnService returns(c, p, l);
  AccountService account(p, l, c);
  //controlLoop(c, p, checkout, returns, account);

  //QT Window launch
  QApplication a(argc, argv);
  MainWindow w(c, p, l, h);

  w.loadCatalogue();
  w.show();
  return a.exec();
}

/* just a temporary loop for testing functionality
void controlLoop(Catalogue& cat, PatronRepo& pat, checkOutService& checkout, returnService& returns, AccountService& account)  {

  int opt=0;

  while(true){
    cout << "\n\n****** Option Menu *******\n" << endl;
    cout << "0: exit  1: Browse/View all catalogue Items  2: View all Patrons  3: Borrow Item  4: Return Item  5: Place Hold  6: Cancel Hold  7: View Account Status\n" << endl;
    
    cin >> opt;

    switch(opt) {
      case 1:  // Browse
        cat.printItems();
        break;

      case 2:  // view patrons
        pat.printAllPatrons();
        break;

      case 3: { // borrow
        int patronId, itemId;
        std::cout << "Patron ID: "; std::cin >> patronId;
        std::cout << "Item ID:   "; std::cin >> itemId;
        std::cout << checkout.checkOutItem(patronId, itemId) << "\n";
        break;
      }

      case 4: { // Return
        int patronId, itemId;
        std::cout << "Patron ID: "; std::cin >> patronId;
        std::cout << "Item ID:   "; std::cin >> itemId;
        std::cout << returns.returnItem(patronId, itemId) << "\n";
        break;
      }

    case 7: { // Account Status (active loans)
        int patronId;
        std::cout << "Patron ID: "; std::cin >> patronId;
        account.displayActiveLoans(patronId);  // prints title, due date, days remaining
        break;
      }

    case 0:
      return;
    }
  }


}*/
