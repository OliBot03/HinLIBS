#include <iostream>
#include <vector>
#include "UserDefs.h"
#include "ObjectDefs.h"
using namespace std;
//Hello this is a test!

class Catalogue {
  private:
    vector<Item> items;
  public:
    Catalogue();
    void addItem(const Item& item);
    void seeCatalogue();
};
int main(){
  cout<<"Hello world!"<<endl;
  Catalogue c = Catalogue();
  c.seeCatalogue();
}

void Catalogue::addItem(const Item& item){
  items.push_back(item);
}

void Catalogue::seeCatalogue(){
  for (int i = 0; i < items.size(); i++)
    cout << items[i] << endl;
}

Catalogue::Catalogue(){
  addItem(FictionBook("F1", "Oliver", "111"));
  addItem(FictionBook("F2", "Oliver", "112"));
  addItem(FictionBook("F3", "Oliver", "113"));
  addItem(FictionBook("F4", "Oliver", "114"));
  addItem(FictionBook("F5", "Oliver", "115"));
  addItem(NonFictionBook("NF1", "Oliver", "211", "D1"));
  addItem(NonFictionBook("NF2", "Oliver", "212", "D2"));
  addItem(NonFictionBook("NF3", "Oliver", "213", "D3"));
  addItem(NonFictionBook("NF4", "Oliver", "214", "D4"));
  addItem(NonFictionBook("NF5", "Oliver", "215", "D5"));
  addItem(Magazine("M1", "Oliver", "311", "1", "Jan 2020"));
  addItem(Magazine("M2", "Oliver", "312", "2", "Feb 2020"));
  addItem(Magazine("M3", "Oliver", "313", "3", "Mar 2020"));
  addItem(Movie("MO1", "Director Oliver", "Horror", "R"));
  addItem(Movie("MO2", "Director Oliver", "Fantasy", "PG-13"));
  addItem(Movie("MO3", "Director Oliver", "Action", "PG"));
  addItem(VideoGame("VG1", "Game Dev Oliver", "Action", "PG"));
  addItem(VideoGame("VG2", "Game Dev Oliver", "Rogue-lite", "PG-13"));
  addItem(VideoGame("VG3", "Game Dev Oliver", "Horror", "R"));
  addItem(VideoGame("VG4", "Game Dev Oliver", "FPS", "R"));
  cout<<"Catalogue created!"<<endl;
}