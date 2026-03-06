#include "Queue.h"

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node<T>* node = new Node<T>(value);
    if (!rearNode) {
        frontNode = rearNode = node;
    }
    else {
        rearNode->next = node;
        rearNode = node;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (!frontNode) throw std::out_of_range("Queue is empty");
    Node<T>* temp = frontNode;
    T val = temp->data;
    frontNode = frontNode->next;
    if (!frontNode) rearNode = nullptr;
    delete temp;
    return val;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

template <typename T>
void Queue<T>::print() const {
    Node<T>* curr = frontNode;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
