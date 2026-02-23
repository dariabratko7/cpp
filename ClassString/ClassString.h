#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <initializer_list>

using namespace std;

class MyString {
private:
    char* str;
    size_t length;
    size_t capacity;
    static int objectCount;

public:

    MyString();
    MyString(size_t size);
    MyString(const char* input);
    MyString(const MyString& other);
    MyString(initializer_list<char> list);


    ~MyString();

    void MyStrcpy(MyString& obj);
    bool MyFindStr(const char* substr);
    int MyFindChr(char c);
    size_t MyStrLen() const;
    size_t getCapacity() const;

    static int getObjectCount();

    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    char& operator[](size_t index);

    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator==(const MyString& other) const;


    friend ostream& operator<<(ostream& os, const MyString& obj);
    friend istream& operator>>(istream& is, MyString& obj);
};

#endif
