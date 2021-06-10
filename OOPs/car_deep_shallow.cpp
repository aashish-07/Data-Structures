#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    float price;

public:
    int model;
    char *name;
// Constructor
    Car()
    {
        name = NULL;
    };
    // parameterised constructor
    Car(float p, int m, char *n)
    {
        price = p;
        model = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Car(Car &X){
        price = X.price;
        model = X.model;
        // deep copy
        name = name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
    }
    void print()
    {
        cout << "Name " << name << endl;
        cout << "Model No. " << model << endl;
        cout << "Price  " << price << endl;
    }
};

int main()
{
    Car d(112, 220, "Tata");
    Car e(d);
    e.name[0] = 'B'; 
    d.print();
    e.print();

    return 0;
}