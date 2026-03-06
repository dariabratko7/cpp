#pragma once
#include <iostream>
using namespace std;

class MyString {
    char* str;
public:
    MyString() : str(nullptr) {}
    MyString(const char* s) {
        if (s) {
            int len = 0; while (s[len]) len++;
            str = new char[len + 1];
            for (int i = 0; i <= len; i++) str[i] = s[i];
        }
        else str = nullptr;
    }
    MyString(const MyString& other) {  
        if (other.str) {
            int len = 0; while (other.str[len]) len++;
            str = new char[len + 1];
            for (int i = 0; i <= len; i++) str[i] = other.str[i];
        }
        else str = nullptr;
    }
    MyString(MyString&& other) noexcept { 
        str = other.str;
        other.str = nullptr;
    }
    MyString& operator=(const MyString& other) { 
        if (this != &other) {
            delete[] str;
            if (other.str) {
                int len = 0; while (other.str[len]) len++;
                str = new char[len + 1];
                for (int i = 0; i <= len; i++) str[i] = other.str[i];
            }
            else str = nullptr;
        }
        return *this;
    }
    MyString& operator=(MyString&& other) noexcept 
        if (this != &other) {
            delete[] str;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }
    ~MyString() { delete[] str; }

    friend ostream& operator<<(ostream& out, const MyString& s) {
        if (s.str) out << s.str;
        return out;
    }
    friend istream& operator>>(istream& in, MyString& s) {
        char buffer[256];
        in >> buffer;
        delete[] s.str;
        int len = 0; while (buffer[len]) len++;
        s.str = new char[len + 1];
        for (int i = 0; i <= len; i++) s.str[i] = buffer[i];
        return in;
    }
};
