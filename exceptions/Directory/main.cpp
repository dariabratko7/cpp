#include <iostream>
#include "Directory.h"

using namespace std;

void printRecords(const vector<Record>& recs) {
    for (auto& r : recs) {
        cout << "Назва фірми: " << r.companyName << "\n";
        cout << "Власник: " << r.owner << "\n";
        cout << "Телефон: " << r.phone << "\n";
        cout << "Адреса: " << r.address << "\n";
        cout << "Рід діяльності: " << r.activity << "\n";
        cout << "-----------------------------\n";
    }
}

int main() {
    Directory dir("directory.txt");
    int choice;
    do {
        cout << "\n1. Показати всі записи\n";
        cout << "2. Додати запис\n";
        cout << "3. Пошук за назвою фірми\n";
        cout << "4. Пошук за власником\n";
        cout << "5. Пошук за телефоном\n";
        cout << "6. Пошук за родом діяльності\n";
        cout << "0. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            dir.showAll();
        }
        else if (choice == 2) {
            Record r;
            cout << "Назва фірми: "; getline(cin, r.companyName);
            cout << "Власник: "; getline(cin, r.owner);
            cout << "Телефон: "; getline(cin, r.phone);
            cout << "Адреса: "; getline(cin, r.address);
            cout << "Рід діяльності: "; getline(cin, r.activity);
            dir.addRecord(r);
            cout << "Запис додано.\n";
        }
        else if (choice == 3) {
            string s; cout << "Введіть назву фірми: "; getline(cin, s);
            printRecords(dir.searchByCompany(s));
        }
        else if (choice == 4) {
            string s; cout << "Введіть власника: "; getline(cin, s);
            printRecords(dir.searchByOwner(s));
        }
        else if (choice == 5) {
            string s; cout << "Введіть телефон: "; getline(cin, s);
            printRecords(dir.searchByPhone(s));
        }
        else if (choice == 6) {
            string s; cout << "Введіть рід діяльності: "; getline(cin, s);
            printRecords(dir.searchByActivity(s));
        }
    } while (choice != 0);

    return 0;
}