#pragma once
#include <iostream>
#include <cstring>

class Mysting {
private:
    char* str;
public:
    Mysting();
    Mysting(const char* s);
    Mysting(const Mysting& other);
    Mysting& operator=(const Mysting& other);
    ~Mysting();

    const char* c_str() const;
};
