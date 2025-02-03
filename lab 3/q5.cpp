#include <iostream>
#include <string>
using namespace std;

class Book {
   private:
     string name;
     string ISBN;
     string author;
     string publisher;

   public:
     Book(string n, string i, string a, string p) : name(n), ISBN(i), author(a), publisher(p) {};

     string getBookInfo() {
        return "Name: " + name + "\nISBN: " + ISBN + "\nAuthor: " + author + "\nPublisher: " + publisher;  
     }    
};

int main(int argc, char const *argv[])
{
    Book books[5] = {
        {"Movie 1", "ISBN 1", "Author 1", "Publisher 1"},
        {"Movie 2", "ISBN 2", "Author 2", "Publisher 2"},
        {"Movie 3", "ISBN 3", "Author 3", "Publisher 3"},
        {"Movie 4", "ISBN 4", "Author 4", "Publisher 4"},
        {"Movie 5", "ISBN 5", "Author 5", "Publisher 5"}
    };
    for (auto book : books) {
        cout << book.getBookInfo() << endl;
    }
    return 0;
    
}
