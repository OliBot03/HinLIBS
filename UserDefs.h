#ifndef USERDEFS_H
#define USERDEFS_H
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "ObjectDefs.h"
#include "Loan.h"
using namespace std;

class Patron {
  private:
    inline static int nextPatronId = 2001;
    int patronId; //make this more meaningful (tie it to the fake "authentication" for the session maybe)

    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    int activeLoanCount;
    vector<Loan*> activeLoans;

    //Holds
    
    

  public:
    Patron(const string& username, const string& password, const string& name, const string& email, const string& phoneNumber) 
      :  patronId(nextPatronId++), username(username), password(password), name(name), email(email), phoneNumber(phoneNumber), activeLoanCount(0) {}

    string getUsername() const {return username;}
    int getPatronId() const {return patronId;}
    int getActiveLoanCount() const {return activeLoanCount;}
    void addActiveLoan(int itemID) {
        activeLoans.push_back(new Loan(patronId, itemID, 14));
        activeLoanCount++;
    }
    void removeActiveLoan(int itemID) {activeLoanCount--;}
    bool validateLogin(string p){ return p==password;}
    void printPatron(ostream& os) const {
      os << " ID: " << patronId << "\n Username: " << username << "\n Password: " << password << "\n Name: " << name
        << "\n Email: " << email << "\n phoneNumber: " << phoneNumber;
    }

    vector<Loan*>& getLoans(){ return activeLoans;}
    
};




//For the future:
/*class Librarian {

};

class SystemAdmin {

};*/

#endif
