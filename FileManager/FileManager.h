#pragma once
#include <string>

using namespace std;

class FileManager {
public:
    void showDirectory(const string& path);
    void createFile(const string& path);
    void createDirectory(const string& path);
    void remove(const string& path);
    void rename(const string& oldName, const string& newName);
    void copy(const string& from, const string& to);
    void move(const string& from, const string& to);
    void getSize(const string& path);
    void search(const string& path, const string& mask);
};
