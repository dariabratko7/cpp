#include "ClassString.h"

using namespace std;

int MyString::objectCount = 0;

MyString::MyString() : MyString(80) {}

MyString::MyString(size_t size) : capacity(size), length(0) {
    str = new char[capacity + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(const char* input)
    : capacity(strlen(input)), length(strlen(input)) {

    str = new char[capacity + 1];
    strcpy(str, input);
    objectCount++;
}

MyString::MyString(const MyString& other)
    : capacity(other.capacity), length(other.length) {

    str = new char[capacity + 1];
    strcpy(str, other.str);
    objectCount++;
}

MyString::MyString(initializer_list<char> list)
    : capacity(list.size()), length(list.size()) {

    str = new char[capacity + 1];

    size_t i = 0;
    for (char c : list) {
        str[i++] = c;
    }

    str[length] = '\0';
    objectCount++;
}

MyString::~MyString() {
    delete[] str;
    objectCount--;
}

void MyString::MyStrcpy(MyString& obj) {

    if (capacity < obj.length) {
        delete[] str;
        capacity = obj.length;
        str = new char[capacity + 1];
    }

    strcpy(str, obj.str);
    length = obj.length;
}

bool MyString::MyFindStr(const char* substr) {
    return strstr(str, substr) != nullptr;
}

int MyString::MyFindChr(char c) {

    for (size_t i = 0; i < length; i++) {
        if (str[i] == c)
            return i;
    }

    return -1;
}

size_t MyString::MyStrLen() const {
    return length;
}

size_t MyString::getCapacity() const {
    return capacity;
}

int MyString::getObjectCount() {
    return objectCount;
}

MyString& MyString::operator=(const MyString& other) {

    if (this != &other) {

        delete[] str;

        capacity = other.capacity;
        length = other.length;

        str = new char[capacity + 1];
        strcpy(str, other.str);
    }

    return *this;
}
MyString MyString::operator+(const MyString& other) const {

    MyString temp(length + other.length);

    strcpy(temp.str, str);
    strcat(temp.str, other.str);

    temp.length = length + other.length;

    return temp;
}

MyString& MyString::operator+=(const MyString& other) {

    if (capacity < length + other.length) {

        capacity = length + other.length;

        char* newStr = new char[capacity + 1];

        strcpy(newStr, str);
        strcat(newStr, other.str);

        delete[] str;
        str = newStr;
    }
    else {
        strcat(str, other.str);
    }

    length += other.length;

    return *this;
}


char& MyString::operator[](size_t index) {
    return str[index];
}

bool MyString::operator>(const MyString& other) const {
    return strcmp(str, other.str) > 0;
}

bool MyString::operator<(const MyString& other) const {
    return strcmp(str, other.str) < 0;
}

bool MyString::operator==(const MyString& other) const {
    return strcmp(str, other.str) == 0;
}
 
ostream& operator<<(ostream& os, const MyString& obj) {
    os << obj.str;
    return os;
}
 
istream& operator>>(istream& is, MyString& obj) {

    is.getline(obj.str, obj.capacity + 1);
    obj.length = strlen(obj.str);

    return is;
}