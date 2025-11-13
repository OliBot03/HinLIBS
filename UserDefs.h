#ifndef USERDEFS_H
#define USERDEFS_H
#include <string>
#include <iostream>
#include <memory>
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

    //Active loans
    //Holds
    
    

  public:
    Patron(const string& username, const string& password, const string& name, const string& email, const string& phoneNumber) 
      :  patronId(nextPatronId++), username(username), password(password), name(name), email(email), phoneNumber(phoneNumber), activeLoanCount(0) {}

    string getUsername() const {return username;}
    int getPatronId() const {return patronId;}
    int getActiveLoanCount() const {return activeLoanCount;}
    void addActiveLoan() {activeLoanCount++;}
    void removeActiveLoan() {activeLoanCount--;}
    bool validateLogin(string p){ return p==password;}
    void printPatron() const {
      cout << "ID: " << patronId << ", Username: " << username << ", Password: " << password << ", Name: " << name 
        << ", Email: " << email << ", phoneNumber: " << phoneNumber;
    }

    
};




//For the future:
/*class Librarian {

};

class SystemAdmin {

};*/

#endif
