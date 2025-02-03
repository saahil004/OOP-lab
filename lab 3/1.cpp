#include <iostream>
#include <string>
using namespace std;

class User {
  public:
   string Name;
   int Age;
};

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Invalid Arguements" << endl;
        return 0;
    }
    User u1 = {argv[1], stoi(argv[2])};
    cout << "My name is " << u1.Name << " and I'm " << u1.Age << " years old." << endl;
    return 0;
}