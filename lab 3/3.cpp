#include <iostream>
#include <string>
using namespace std;

class Glass {
    public:
      int LiquidLevel = 200;

      void drink(int mm) {
        if (mm >= LiquidLevel)
        {
            LiquidLevel = 0;
        } else {
            LiquidLevel -= mm;
        }
        refill();
      }

        void refill() {
            if (LiquidLevel <= 100)
            {
                LiquidLevel = 200;
                cout << "Refilled." << endl;
            }
            
        }

        void display() {
            cout << "Liquid level: " << LiquidLevel << endl;
        }
      
};


int main(int argc, char const *argv[])
{
    Glass myGlass;
    int c = 0;
    int l;
    while (c != 2)
    {
        cout << "Enter 1 to drink.\nEnter 2 to exit.\nChoice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter mm to drink: ";
            cin >> l;
            myGlass.drink(l);
            myGlass.display();
            break;
        }    
    }
    
    return 0;
}


