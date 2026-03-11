#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class FileHandler {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file) {
            cout << "Не вдалося відкрити файл\n";
            return;
        }
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    virtual ~FileHandler() {}
};

class ASCIIFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file) { cout << "Не вдалося відкрити файл\n"; return; }
        char ch;
        while (file.get(ch)) {
            cout << int(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (!file) { cout << "Не вдалося відкрити файл\n"; return; }
        char ch;
        while (file.get(ch)) {
            cout << bitset<8>(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

int main() {
    int choice;
    cout << "Оберіть спосіб відображення файлу:\n1. Текст\n2. ASCII-коди\n3. Двоїчний вид\nВибір: ";
    cin >> choice;
    cin.ignore();

    string path;
    cout << "Введіть шлях до файлу: ";
    getline(cin, path);

    FileHandler* handler = nullptr;

    switch (choice) {
    case 1: handler = new FileHandler(); break;
    case 2: handler = new ASCIIFileHandler(); break;
    case 3: handler = new BinaryFileHandler(); break;
    default: cout << "Невірний вибір\n"; return 0;
    }

    handler->Display(path.c_str());
    delete handler;

    return 0;
}