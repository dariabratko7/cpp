#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    string characteristic;
public:
    Pet(const string& n, const string& c) : name(n), characteristic(c) {}
    virtual void ShowInfo() const {
        cout << "Ім'я: " << name << ", Характеристика: " << characteristic << endl;
    }
    virtual ~Pet() {}
};

class Dog : virtual public Pet {
public:
    Dog(const string& n, const string& c) : Pet(n, c) {}
    void ShowInfo() const override {
        cout << "Собака - ";
        Pet::ShowInfo();
    }
};

class Cat : virtual public Pet {
public:
    Cat(const string& n, const string& c) : Pet(n, c) {}
    void ShowInfo() const override {
        cout << "Кішка - ";
        Pet::ShowInfo();
    }
};

class Parrot : virtual public Pet {
public:
    Parrot(const string& n, const string& c) : Pet(n, c) {}
    void ShowInfo() const override {
        cout << "Папуга - ";
        Pet::ShowInfo();
    }
};

int main() {
    int choice;
    cout << "Оберіть тварину для створення:\n1. Собака\n2. Кішка\n3. Папуга\nВибір: ";
    cin >> choice;
    cin.ignore();

    string name, characteristic;
    cout << "Введіть ім'я: ";
    getline(cin, name);
    cout << "Введіть характеристику: ";
    getline(cin, characteristic);

    Pet* pet = nullptr;

    switch (choice) {
    case 1: pet = new Dog(name, characteristic); break;
    case 2: pet = new Cat(name, characteristic); break;
    case 3: pet = new Parrot(name, characteristic); break;
    default: cout << "Невірний вибір\n"; return 0;
    }

    cout << "\nІнформація про тварину:\n";
    pet->ShowInfo();

    delete pet;
    return 0;
}