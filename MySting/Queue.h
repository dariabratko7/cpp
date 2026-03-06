#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
public:
    Queue();
    ~Queue();

    void enqueue(const T& value);
    T dequeue();
    bool isEmpty() const;
    void print() const;
};
