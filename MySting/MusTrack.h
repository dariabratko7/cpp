#pragma once
#include "Mysting.h"
#include <iostream>

class MusTrack {
public:
    Mysting name;
    Mysting author;
    Mysting duration;

    MusTrack() = default;
    MusTrack(const Mysting& n, const Mysting& a, const Mysting& d)
        : name(n), author(a), duration(d) {
    }

    void print() const;
};
