#include "FileManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = filesystem;

void FileManager::showDirectory(const string& path) {
    for (auto& p : fs::directory_iterator(path)) {
        cout << p.path() << endl;
    }
}

void FileManager::createFile(const string& path) {
    ofstream file(path);
    file.close();
}

void FileManager::createDirectory(const string& path) {
    fs::create_directory(path);
}

void FileManager::remove(const string& path) {
    fs::remove_all(path);
}

void FileManager::rename(const string& oldName, const string& newName) {
    fs::rename(oldName, newName);
}

void FileManager::copy(const string& from, const string& to) {
    fs::copy(from, to, fs::copy_options::recursive);
}

void FileManager::move(const string& from, const string& to) {
    fs::rename(from, to);
}

void FileManager::getSize(const string& path) {
    uintmax_t size = 0;

    if (fs::is_regular_file(path)) {
        size = fs::file_size(path);
    }
    else {
        for (auto& p : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(p))
                size += fs::file_size(p);
        }
    }

    cout << "Size: " << size << " bytes\n";
}

void FileManager::search(const string& path, const string& mask) {
    for (auto& p : fs::recursive_directory_iterator(path)) {
        if (p.path().filename().string().find(mask) != string::npos) {
            cout << p.path() << endl;
        }
    }
}