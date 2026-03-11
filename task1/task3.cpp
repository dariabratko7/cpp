#include <iostream>

using namespace std;

class Wheels
{
protected:
    int wheelCount;

public:
    Wheels(int w)
    {
        wheelCount = w;
    }
};

class Engine
{
protected:
    int power;

public:
    Engine(int p)
    {
        power = p;
    }
};

class Doors
{
protected:
    int doorCount;

public:
    Doors(int d)
    {
        doorCount = d;
    }
};

class Car : public Wheels, public Engine, public Doors
{
public:
    Car(int w, int p, int d) : Wheels(w), Engine(p), Doors(d) {}

    void info()
    {
        cout << "Car information:" << endl;
        cout << "Wheels: " << wheelCount << endl;
        cout << "Engine power: " << power << endl;
        cout << "Doors: " << doorCount << endl;
    }
};

int main()
{
    Car car(4, 150, 4);
    car.info();

    return 0;
}