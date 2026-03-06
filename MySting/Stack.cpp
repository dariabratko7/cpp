
#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
    capacity = 15;
    arr = new T[capacity];
    topIndex = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <typename T>
void Stack<T>::resize() {
    capacity += 16;
    T* newArr = new T[capacity];
    for (int i = 0; i <= topIndex; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (topIndex + 1 >= capacity) resize();
    arr[++topIndex] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (topIndex < 0) throw std::out_of_range("Stack is empty");
    return arr[topIndex--];
}

template <typename T>
T Stack<T>::top() const {
    if (topIndex < 0) throw std::out_of_range("Stack is empty");
    return arr[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
int Stack<T>::size() const {
    return topIndex + 1;
}

