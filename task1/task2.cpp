#include <iostream>

using namespace std;

class Square
{
protected:
    double side;

public:
    Square(double s)
    {
        side = s;
    }
};

class Circle
{
protected:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }
};

class CircleInSquare : public Square, public Circle
{
public:
    CircleInSquare(double s) : Square(s), Circle(s / 2) {}

    void show()
    {
        cout << "Side of square: " << side << endl;
        cout << "Radius of circle: " << radius << endl;
    }
};

int main()
{
    CircleInSquare obj(10);
    obj.show();

    return 0;
}