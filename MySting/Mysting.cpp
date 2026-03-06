#include "Mysting.h"

Mysting::Mysting() {
    str = new char[1];
    str[0] = '\0';
}

Mysting::Mysting(const char* s) {
    if (s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else {
        str = new char[1];
        str[0] = '\0';
    }
}

Mysting::Mysting(const Mysting& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

Mysting& Mysting::operator=(const Mysting& other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    return *this;
}

Mysting::~Mysting() {
    delete[] str;
}

const char* Mysting::c_str() const {
    return str;
}