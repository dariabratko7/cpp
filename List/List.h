#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    Node<T>* m_head = nullptr;
    unsigned int m_size = 0;

public:
    List() {}
    List(const List& other) : m_head(nullptr), m_size(0) { Assign(other); }
    ~List() { RemoveAll(); }

    List& operator=(const List& right)
    {
        if (this != &right) Assign(right);
        return *this;
    }

    void Add(const T& data);
    void Print() const;
    void RemoveHead();
    void RemoveAll();
    void Assign(const List& other);

    void Insert(const T& data, unsigned int index);
    void RemoveAt(unsigned int index);

    unsigned int GetSize() const { return m_size; }
};
