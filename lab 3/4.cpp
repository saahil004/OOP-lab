#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
       string fname, lname;
       double salary;
    public:
       Employee(string f, string l, double sal) {
        fname = f;
        lname = l;
        (sal > 0) ? salary = sal : salary = 0.0;
       }   

       void giveRaise() {
           salary = 0.1*salary + salary;
       }

       double getYearlySalary() {
           return 12*salary;
       }
};

int main(int argc, char const *argv[])
{
    if (argc < 7)
    {
        cout << "Less arguements.\n";
        return 0;
    }
    Employee e1 = Employee(argv[1], argv[2], stod(argv[3]));
    Employee e2 = Employee(argv[4], argv[5], stod(argv[6]));
    cout << "Employee 1's yearly salary: " << e1.getYearlySalary() << endl;
    cout << "Employee 2's yearly salary: " << e2.getYearlySalary() << endl;
    e1.giveRaise();
    e2.giveRaise();
    cout << "\nAfter 10% raise " << endl;
    cout << "Employee 1's yearly salary: " << e1.getYearlySalary() << endl;
    cout << "Employee 2's yearly salary: " << e2.getYearlySalary() << endl;
    return 0;
}
