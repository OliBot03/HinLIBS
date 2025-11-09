#ifNDEF USERDEFS_H

#include <Stuff>

#DEFINE USERDEFS_H

class Patron {
  private:
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    //Active loans
    //Holds
    double fines;

  public:
    Patron(const string& username, const string& password, const string& name, const string& email, const string& phoneNumber) : username(username), password(password), name(name), email(email), phoneNumber(phoneNumber)
};


//For the future:
/*class Librarian {

};

class SystemAdmin {

};*/