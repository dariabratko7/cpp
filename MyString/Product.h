#pragma once
#include "MyString.h"
#include <iostream>
using namespace std;

class Product {
    MyString name;
    double price;
public:
    Product() : name(""), price(0.0) {}
    Product(const MyString& n, double p) : name(n), price(p) {}
    Product(const Product& other) : name(other.name), price(other.price) {} // copy
    Product(Product&& other) noexcept : name(move(other.name)), price(other.price) {} // move

    Product& operator=(const Product& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
        }
        return *this;
    }
    Product& operator=(Product&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            price = other.price;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Product& p) {
        out << p.name << " : " << p.price;
        return out;
    }
    friend istream& operator>>(istream& in, Product& p) {
        in >> p.name >> p.price;
        return in;
    }
};
