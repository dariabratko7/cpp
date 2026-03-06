#include "List.h"
#include "Person.h"
#include <iostream>
using namespace std;

int main()
{
    List<Person> list;

    list.Add(Person("Alice", 30));
    list.Add(Person("Bob", 25));
    list.Add(Person("Charlie", 20));

    cout << "Initial list:\n";
    list.Print();

    cout << "\nInsert Dave at index 1:\n";
    list.Insert(Person("Dave", 40), 1);
    list.Print();

    cout << "\nRemove at index 2:\n";
    list.RemoveAt(2);
    list.Print();

    cout << "\nList size: " << list.GetSize() << endl;

    return 0;
}