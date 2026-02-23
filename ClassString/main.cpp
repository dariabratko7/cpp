#include "ClassString.h"

using namespace std;

int main() {

    MyString s1;
    MyString s2 = { 'a','b','c' };
    MyString s3("Hello");
    MyString s4 = s3;

    cout << "Введіть рядок: ";
    cin >> s1;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    MyString s5 = s2 + s3;
    cout << "s5: " << s5 << endl;

    cout << "Кількість об'єктів: "
        << MyString::getObjectCount() << endl;

    return 0;
}