#include <iostream>
#include <fstream>
#include "doubly_linked_list.h"
#include "exceptions.h"

using namespace std;

int main() {
    DoublyLinkedList list;

    try {
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        cout << "Список після додавання елементів: ";
        list.print();

        list.pop_back();
        list.pop_back();
        list.pop_back();

        cout << "Список після видалення всіх елементів: ";
        list.print();

        list.pop_back(); 

    }
    catch (const MyException& ex) {
        cout << ex.what() << endl;
    }

    try {
        int a = 10, b = 0;
        if (b == 0) throw DivisionByZeroException();
        cout << "Результат ділення: " << a / b << endl;

    }
    catch (const MyException& ex) {
        cout << ex.what() << endl;
    }

    try {
        ifstream file("nonexistent.txt");
        if (!file.is_open()) throw FileOpenException();
        file.close();

    }
    catch (const MyException& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}