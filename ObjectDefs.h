//Here we define the object types and their properties
#ifndef OBJECTDEFS_H
#define OBJECTDEFS_H
#include <string>
#include <iostream>
using namespace std;

//General Item class:
class Item {
  
  protected:
    inline static int nextItemId = 1001;
    string title;
    string author;
    int itemId;
    bool checkedOut;

    Item(std::string t, std::string c) : title(std::move(t)), author(std::move(c)), itemId(nextItemId++) {}
  
  public:
    virtual ~Item() = default;                
    virtual void getType() const = 0; 
    virtual void print(std::ostream& os) const = 0;
    
    int getItemId() const { return itemId; }
    const std::string& getTitle() const { return title; }
    bool isCheckedOut() const { return checkedOut; }
    void markCheckedOut() { checkedOut = true; }
    void markAvailable() { checkedOut = false; }
};

class FictionBook: public Item {
  private:
    string isbn;

  public:
    FictionBook(const string& title, const string& author, const string& isbn) : Item(title, author), isbn(isbn) {checkedOut = false;}
    void getType() const override {cout<<"FictionBook"<<endl;}
    void print(ostream& os) const override {
      os << " ID: " << getItemId() << "\n Title: " << title << "\n Author: " << author << "\n ISBN: "
        << isbn << "\n Availability Status: " << (isCheckedOut() ? "Checked Out" : "Available");
    }
};

class NonFictionBook: public Item {
  private:
    string isbn;
    string DeweyDecimal;

  public:
    NonFictionBook(const string& title, const string& author, const string& isbn, const string& DeweyDecimal) 
      : Item(title, author), isbn(isbn), DeweyDecimal(DeweyDecimal) { checkedOut = false;}
    void getType() const override {cout<<"NonFictionBook"<<endl;}
    void print(ostream& os) const override {
      os << " ID: " << getItemId() << "\n Title: " << title << "\n Author: " << author << "\n ISBN: "
        << isbn << "\n Dewey Decimal: " << DeweyDecimal << "\n Availability Status: " << (isCheckedOut() ? "Checked Out" : "Available");
    }
};

class Magazine: public Item {
  private:
    string issueNumber;
    string publicationDate;

  public:  
    Magazine(const string& title, const string& author, const string& issueNumber, const string& publicationDate) 
      : Item(title, author), issueNumber(issueNumber), publicationDate(publicationDate) { checkedOut = false; }
    void getType() const override {cout<<"Magazine"<<endl;}
    void print(ostream& os) const override{
      os << " ID: " << getItemId() << "\n Title: " << title << "\n Author: " << author << "\n Issue Number: "
        << issueNumber << "\n Publication Date: " << publicationDate << "\n Availability Status: " << (isCheckedOut() ? "Checked Out" : "Available");
    }
};

class Movie: public Item {
  private:
    string genre;
    string rating;

  public:
    Movie(const string& title, const string& author, const string& genre, const string& rating) 
      : Item(title, author), genre(genre), rating(rating) { checkedOut = false; }
    void getType() const override {cout<<"Movie"<<endl;}
    void print(ostream& os) const override {
      os << " ID: " << getItemId() << "\n Title: " << title << "\n Author: " << author << "\n Genre: "
        << genre << "\n Rating: " << rating << "\n Availability Status: "<< (isCheckedOut() ? "Checked Out" : "Available");
    }
};

class VideoGame: public Item {
  private:
    string genre;
    string rating;

  public:
    VideoGame(const string& title, const string& author, const string& genre, const string& rating) 
      : Item(title, author), genre(genre), rating(rating) { checkedOut = false; }
    void getType() const override {cout<<"VideoGame"<<endl;}
    void print(ostream& os) const override {
      os << " ID: " << getItemId() << "\n Title: " << title << "\n Author: " << author << "\n Genre: " << genre
        << "\n Rating: "<<rating << "\n Availability Status: " << (isCheckedOut() ? "Checked Out" : "Available");
    }
};

#endif
