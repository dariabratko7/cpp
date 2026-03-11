#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    string name;
    double area;

    Room(string name, double area) {
        this->name = name;
        this->area = area;
    }

    void show() {
        cout << name << " - " << area << " m2" << endl;
    }
};

class House {
public:
    string address;
    int floors;
    vector<Room> rooms;

    House(string address, int floors) {
        this->address = address;
        this->floors = floors;
    }

    void addRoom(string name, double area) {
        rooms.push_back(Room(name, area));
    }

    void showRooms() {
        cout << "House: " << address << endl;

        for (Room& r : rooms) {
            r.show();
        }
    }
};

int main() {

    House h("Shevchenko 10", 2);

    h.addRoom("Bedroom", 20);
    h.addRoom("Kitchen", 12);

    h.showRooms();

    return 0;
}