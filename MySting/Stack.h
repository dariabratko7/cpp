#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;
    void resize();
public:
    Stack();
    ~Stack();

    void push(const T& value);
    T pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
};

