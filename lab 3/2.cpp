#include <iostream>
#include <string>
using namespace std;

class Date {
  public:
    int dd, mm, yyyy;
    void displayDate() {
        cout << this->dd << "/" << this->mm << "/" << this->yyyy << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Invalid Arguements" << endl;
        return 0;
    }
    Date d1 = {stoi(argv[1]), stoi(argv[2]), stoi(argv[3])};
    d1.displayDate();
    return 0;
}