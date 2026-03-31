#include "Directory.h"
#include <fstream>
#include <iostream>
#include <sstream>

Directory::Directory(const string& file) {
    filename = file;
    loadFromFile();
}

void Directory::loadFromFile() {
    ifstream in(filename);
    if (!in.is_open()) return;

    records.clear();
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        Record r;
        getline(ss, r.companyName, ';');
        getline(ss, r.owner, ';');
        getline(ss, r.phone, ';');
        getline(ss, r.address, ';');
        getline(ss, r.activity, ';');
        records.push_back(r);
    }
    in.close();
}

void Directory::saveToFile() {
    ofstream out(filename);
    for (auto& r : records) {
        out << r.companyName << ";"
            << r.owner << ";"
            << r.phone << ";"
            << r.address << ";"
            << r.activity << ";\n";
    }
    out.close();
}

void Directory::addRecord(const Record& r) {
    records.push_back(r);
    saveToFile();
}

void Directory::showAll() const {
    for (auto& r : records) {
        cout << "Назва фірми: " << r.companyName << "\n";
        cout << "Власник: " << r.owner << "\n";
        cout << "Телефон: " << r.phone << "\n";
        cout << "Адреса: " << r.address << "\n";
        cout << "Рід діяльності: " << r.activity << "\n";
        cout << "-----------------------------\n";
    }
}

vector<Record> Directory::searchByCompany(const string& name) const {
    vector<Record> result;
    for (auto& r : records) {
        if (r.companyName.find(name) != string::npos)
            result.push_back(r);
    }
    return result;
}

vector<Record> Directory::searchByOwner(const string& owner) const {
    vector<Record> result;
    for (auto& r : records) {
        if (r.owner.find(owner) != string::npos)
            result.push_back(r);
    }
    return result;
}

vector<Record> Directory::searchByPhone(const string& phone) const {
    vector<Record> result;
    for (auto& r : records) {
        if (r.phone.find(phone) != string::npos)
            result.push_back(r);
    }
    return result;
}

vector<Record> Directory::searchByActivity(const string& activity) const {
    vector<Record> result;
    for (auto& r : records) {
        if (r.activity.find(activity) != string::npos)
            result.push_back(r);
    }
    return result;
}
int main() {
    cout << "Привіт з mybranch" << endl;
    return 0;
}