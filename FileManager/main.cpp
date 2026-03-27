#include <iostream>
#include "FileManager.h"

using namespace std;

int main() {
    FileManager fm;
    int choice;
    string a, b;

    while (true) {
        cout << "\n1.Show\n2.Create File\n3.Create Folder\n4.Delete\n";
        cout << "5.Rename\n6.Copy\n7.Move\n8.Size\n9.Search\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Path: ";
            cin >> a;
            fm.showDirectory(a);
            break;
        case 2:
            cout << "File name: ";
            cin >> a;
            fm.createFile(a);
            break;
        case 3:
            cout << "Folder name: ";
            cin >> a;
            fm.createDirectory(a);
            break;
        case 4:
            cout << "Delete path: ";
            cin >> a;
            fm.remove(a);
            break;
        case 5:
            cout << "Old name: ";
            cin >> a;
            cout << "New name: ";
            cin >> b;
            fm.rename(a, b);
            break;
        case 6:
            cout << "From: ";
            cin >> a;
            cout << "To: ";
            cin >> b;
            fm.copy(a, b);
            break;
        case 7:
            cout << "From: ";
            cin >> a;
            cout << "To: ";
            cin >> b;
            fm.move(a, b);
            break;
        case 8:
            cout << "Path: ";
            cin >> a;
            fm.getSize(a);
            break;
        case 9:
            cout << "Path: ";
            cin >> a;
            cout << "Mask: ";
            cin >> b;
            fm.search(a, b);
            break;
        case 0:
            return 0;
        }
    }
}