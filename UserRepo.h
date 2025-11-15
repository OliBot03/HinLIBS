#ifndef USERREPO_H
#define USERREPO_H
#include "UserDefs.h"
#include <vector>
// you could combine patrons, librarians and sysAdmins into 1 repo? but we don't really need them for D1 so idk
    // and also making a general "user" class doesn't make too much sense since there's practically no shared attributes/member functions

class Patron;
class PatronRepo {

    public:
        PatronRepo();

        void addPatron(unique_ptr<Patron>);
        Patron* getPatronById(int) const;
        void printPatronById(int) const ;
        void printAllPatrons() const;
        Patron* getPatronByUsername(string) const;

    private:
        vector<unique_ptr<Patron>> patrons;


};


//for later :p
class Librarian;
class LibrarianRepo {

    public:
        LibrarianRepo();

        void addLibrarian(unique_ptr<Librarian>);
        Librarian* getLibrarianById(int) const;
        void printLibrarianById(int) const ;
        void printAllLibrarian() const;
        Librarian* getLibrarianByUsername(string) const;

    private:
        vector<unique_ptr<Librarian>> librarians;


};
class SysAdm;
class SysAdmRepo {

    public:
        SysAdmRepo();

        void addSysAdm(unique_ptr<SysAdm>);
        SysAdm* getSysAdmById(int) const;
        void printSysAdmById(int) const ;
        void printAllSysAdm() const;
        SysAdm* getSysAdmByUsername(string) const;

    private:
        vector<unique_ptr<SysAdm>> sysAdms;


};


#endif
