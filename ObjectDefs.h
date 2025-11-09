//Here we define the object types and their properties

#ifndef OBJECTDEFS_H
#include <Stuff>
#define OBJECTDEFS_H

//General Item class:
class Item {
  protected:
    string title;
    string author;
    bool checkOut;

  public:
    void checkOutItem(){};
    void placeHoldItem(){};
    virtual void getType() = 0;
}

class FictionBook: public Item {
  private:
    string isbn;

  public:
    FictionBook(const string& title, const string& author, const string& isbn) : title(title), author(author), isbn(isbn) {checkOut = false;}
    void getType() const override {cout<<"FictionBook"<<endl;}
};

class NonFictionBook: public Item {
  private:
    string isbn;
    string DeweyDecimal;

  public:
    NonFictionBook(const string& title, const string& author, const string& isbn, const string& DeweyDecimal) : title(title), author(author), isbn(isbn), DeweyDecimal(DeweyDecimal){
      checkOut = false;
    }
    void getType() const override {cout<<"NonFictionBook"<<endl;}
};

class Magazine: public Item {
  private:
    string issueNumber;
    string publicationDate;

  public:  
    Magazine(const string& title, const string& author, const string& isbn, const string& issueNumber, const string& publicationDate) : title(title), author(author), isbn(isbn), issueNumber(issueNumber), publicationDate(publicationDate) {
      checkOut = false;
    }
    void getType() const override {cout<<"Magazine"<<endl;}
};

class Movie: public Item {
  private:
    string genre;
    string rating;

  public:
    Movie(const string& title, const string& author, const string& genre, const string& rating) : title(title), author(author), genre(genre), rating(rating) {
      checkOut = false;
    }
    void getType() const override {cout<<"Movie"<<endl;}
};

class VideoGame: public Item {
  private:
    string genre;
    string rating;

  public:
    VideoGame(const string& title, const string& author, const string& genre, const string& rating) : title(title), author(author), genre(genre), rating(rating) {
      checkOut = false;
    }
    void getType() const override {cout<<"VideoGame"<<endl;}
};