#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    float price;

public:
    int model;
    char name[20];

    // Constructor
    Car()
    {
        cout << "C ";
    };
    Car(float p, int m, char *n)
    {
        price = p;
        model = m;
        strcpy(name, n);
    }

    Car(Car &x)
    {
        cout << "Copy Constructir called" << endl;
        price = x.price;
        model = x.model;
        strcpy(name, x.name);
    }

    float apply_discount(float x)
    {
        price = price * (1 - x);
        return price;
    }

    void print()
    {
        cout << "Name " << name << endl;
        cout << "Model No. " << model << endl;
        cout << "Price after discount " << price << endl;
    }

// getters and setters
    void setPrice(float p)
    {
        if (p > 0)
        {
            price = p;
        }
        float msp = 100;
        price = msp;
    }
    float getPrice()
    {
        return price;
    }
};
int main()
{
    Car d(112, 220, "Tata");
    d.print();
    Car c;
    Car e(d); /*Copy Constructor*/
    c.model = 301;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'R';
    c.name[3] = '\0';
    c.setPrice(120);
    float discount;
    cin >> discount;
    cout << "Original Price " << c.getPrice() << endl;
    c.apply_discount(discount);
    c.print();
    return 0;
}
