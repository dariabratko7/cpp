#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>

using namespace std;

struct Record {
    string companyName;
    string owner;
    string phone;
    string address;
    string activity;
};

class Directory {
private:
    vector<Record> records;
    string filename;

    void loadFromFile();
    void saveToFile();
public:
    Directory(const string& file);

    void addRecord(const Record& r);
    void showAll() const;
    vector<Record> searchByCompany(const string& name) const;
    vector<Record> searchByOwner(const string& owner) const;
    vector<Record> searchByPhone(const string& phone) const;
    vector<Record> searchByActivity(const string& activity) const;
};

#endif
