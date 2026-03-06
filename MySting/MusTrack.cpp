#include "MusTrack.h"

void MusTrack::print() const {
    std::cout << "Track: " << name.c_str()
        << ", Author: " << author.c_str()
        << ", Duration: " << duration.c_str() << std::endl;
}