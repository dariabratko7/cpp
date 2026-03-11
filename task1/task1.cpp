#include <iostream>
#include <string>

using namespace std;

class Pet
{
protected:
    string name;
    int age;

public:
    Pet(string n, int a)
    {
        name = n;
        age = a;
    }

    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Dog : public Pet
{
    string breed;

public:
    Dog(string n, int a, string b) : Pet(n, a)
    {
        breed = b;
    }

    void info()
    {
        cout << "Dog:" << endl;
        show();
        cout << "Breed: " << breed << endl << endl;
    }
};

class Cat : public Pet
{
    string color;

public:
    Cat(string n, int a, string c) : Pet(n, a)
    {
        color = c;
    }

    void info()
    {
        cout << "Cat:" << endl;
        show();
        cout << "Color: " << color << endl << endl;
    }
};

class Parrot : public Pet
{
    bool canTalk;

public:
    Parrot(string n, int a, bool t) : Pet(n, a)
    {
        canTalk = t;
    }

    void info()
    {
        cout << "Parrot:" << endl;
        show();
        cout << "Can talk: " << (canTalk ? "Yes" : "No") << endl << endl;
    }
};

int main()
{
    Dog d("Rex", 5, "Shepherd");
    Cat c("Murka", 3, "White");
    Parrot p("Kesha", 2, true);

    d.info();
    c.info();
    p.info();

    return 0;
}
