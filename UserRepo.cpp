#include "UserRepo.h"

PatronRepo::PatronRepo() {
    addPatron(std::make_unique<Patron>("Patron1","Pass1","Name1","Email1", "PhoneNum1"));
    addPatron(std::make_unique<Patron>("Patron2","Pass2","Name2","Email2", "PhoneNum2"));
    addPatron(std::make_unique<Patron>("Patron3","Pass3","Name3","Email3", "PhoneNum3"));
    addPatron(std::make_unique<Patron>("Patron4","Pass4","Name4","Email4", "PhoneNum4"));
    addPatron(std::make_unique<Patron>("Patron5","Pass5","Name5","Email5", "PhoneNum5"));
}


void PatronRepo::addPatron(unique_ptr<Patron> patron) {
    patrons.push_back(std::move(patron));
}

Patron* PatronRepo::getPatronById(int id) const {
    for(size_t i=0; i < patrons.size(); i++) {
        if (patrons.at(i)->getPatronId() == id)
            return patrons.at(i).get();
    }
    //TO DO: If we reach here patron not found, send error message
    return nullptr;
}

Patron* PatronRepo::getPatronByUsername(string username) const {
    for(size_t i=0; i < patrons.size(); i++) {
        if (patrons.at(i)->getUsername() == username)
            return patrons.at(i).get();
    }
    //TO DO: If we reach here patron not found, send error message
    return nullptr;
}

void PatronRepo::printPatronById(int id) const {
    Patron *p1 = getPatronById(id);
    if (p1) {
        p1->printPatron(cout);
    }
    else {
        // Send patron not found message
        p1 = nullptr;
    }
}

void PatronRepo::printAllPatrons() const {
    for(size_t i=0; i < patrons.size(); i++) {
        patrons.at(i)->printPatron(cout);
        cout << endl;
    }
}

LibrarianRepo::LibrarianRepo(){
    addLibrarian(std::make_unique<Librarian>("Librarian1", "Pass1"));
}
SysAdmRepo::SysAdmRepo(){
    addSysAdm(std::make_unique<SysAdm>("SysAdm1", "Pass1"));
}

Librarian* LibrarianRepo::getLibrarianByUsername(string username) const {
    for(size_t i=0; i < librarians.size(); i++) {
        if (librarians.at(i)->getUsername() == username)
            return librarians.at(i).get();
    }
    //TO DO: If we reach here patron not found, send error message
    return nullptr;
}

void LibrarianRepo::addLibrarian(unique_ptr<Librarian> librarian) {
    librarians.push_back(std::move(librarian));
}

SysAdm* SysAdmRepo::getSysAdmByUsername(string username) const {
    for(size_t i=0; i < sysAdms.size(); i++) {
        if (sysAdms.at(i)->getUsername() == username)
            return sysAdms.at(i).get();
    }
    //TO DO: If we reach here patron not found, send error message
    return nullptr;
}

void SysAdmRepo::addSysAdm(unique_ptr<SysAdm> sysAdm) {
    sysAdms.push_back(std::move(sysAdm));
}

