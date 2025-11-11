//Here we define the object types and their properties

#ifndef OBJECTDEFS_H
#define OBJECTDEFS_H
#include <string>
#include <iostream>
using namespace std;

//General Item class:
class Item {
  
  protected:
    Item(std::string t, std::string c) : title(std::move(t)), author(std::move(c)) {}
    string title;
    string author;
    bool checkOut;

  public:
    virtual ~Item() = default;                
    virtual void getType() const = 0; 
    virtual void print(std::ostream& os) const = 0;
};

class FictionBook: public Item {
  private:
    string isbn;

  public:
    FictionBook(const string& title, const string& author, const string& isbn) : Item(title, author), isbn(isbn) {checkOut = false;}
    void getType() const override {cout<<"FictionBook"<<endl;}
    void print(ostream& os) const override {
      os << "Title: " << title << ", Author: " << author << ", ISBN: " 
        << isbn << ", Availability Status: " << ((checkOut) ? "Checked Out" : "Available");
    }
};

class NonFictionBook: public Item {
  private:
    string isbn;
    string DeweyDecimal;

  public:
    NonFictionBook(const string& title, const string& author, const string& isbn, const string& DeweyDecimal) 
      : Item(title, author), isbn(isbn), DeweyDecimal(DeweyDecimal) { checkOut = false;}
    void getType() const override {cout<<"NonFictionBook"<<endl;}
    void print(ostream& os) const override {
      os << "Title: " << title << ", Author: " << author << ", ISBN: " 
        << isbn << ", Dewey Decimal: " << DeweyDecimal << ", Availability Status: " << ((checkOut) ? "Checked Out" : "Available");
    }
};

class Magazine: public Item {
  private:
    string issueNumber;
    string publicationDate;

  public:  
    Magazine(const string& title, const string& author, const string& issueNumber, const string& publicationDate) 
      : Item(title, author), issueNumber(issueNumber), publicationDate(publicationDate) { checkOut = false; }
    void getType() const override {cout<<"Magazine"<<endl;}
    void print(ostream& os) const override{
      os << "Title: " << title << ", Author: " << author << ", Issue Number: " 
        << issueNumber << ", Publication Date: " << publicationDate << ", Availability Status: " << ((checkOut) ? "Checked Out" : "Available");
    }
};

class Movie: public Item {
  private:
    string genre;
    string rating;

  public:
    Movie(const string& title, const string& author, const string& genre, const string& rating) 
      : Item(title, author), genre(genre), rating(rating) { checkOut = false; }
    void getType() const override {cout<<"Movie"<<endl;}
    void print(ostream& os) const override {
      os << "Title: " << title << ", Author: " << author << ", Genre: " 
        << genre << ", Rating: " << rating << ", Availability Status: " << ((checkOut) ? "Checked Out" : "Available");
    }
};

class VideoGame: public Item {
  private:
    string genre;
    string rating;

  public:
    VideoGame(const string& title, const string& author, const string& genre, const string& rating) 
      : Item(title, author), genre(genre), rating(rating) { checkOut = false; }
    void getType() const override {cout<<"VideoGame"<<endl;}
    void print(ostream& os) const override {
      os << "Title: " << title << ", Author: " << author << ", Genre: " << genre
        << ", Rating: "<<rating << ", Availability Status: " << ((checkOut) ? "Checked Out" : "Available");
    }
};

#endif