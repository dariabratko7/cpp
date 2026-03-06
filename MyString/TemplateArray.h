#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Array {
    T* mas;
    int size;
public:
    Array() : size(10) { mas = new T[size]{}; }

    Array(const Array& other) : size(other.size) {
        mas = new T[size];
        for (int i = 0; i < size; i++) mas[i] = other.mas[i];
    }

    Array(Array&& other) noexcept : mas(other.mas), size(other.size) {
        other.mas = nullptr;
        other.size = 0;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] mas;
            size = other.size;
            mas = new T[size];
            for (int i = 0; i < size; i++) mas[i] = other.mas[i];
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] mas;
            mas = other.mas;
            size = other.size;
            other.mas = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Array() { delete[] mas; }

    T& operator[](int index) { return mas[index]; }
    const T& operator[](int index) const { return mas[index]; }
    int GetSize() const { return size; }

    void AddLast(const T& value) {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; i++) temp[i] = mas[i];
        temp[size] = value;
        delete[] mas;
        mas = temp;
        size++;
    }

    void DellLast() {
        if (size <= 0) return;
        T* temp = new T[size - 1];
        for (int i = 0; i < size - 1; i++) temp[i] = mas[i];
        delete[] mas;
        mas = temp;
        size--;
    }

    void Add(int index, const T& value) {
        if (index < 0 || index > size) return;
        T* temp = new T[size + 1];
        for (int i = 0; i < index; i++) temp[i] = mas[i];
        temp[index] = value;
        for (int i = index; i < size; i++) temp[i + 1] = mas[i];
        delete[] mas;
        mas = temp;
        size++;
    }

    void Dell(int index) {
        if (index < 0 || index >= size) return;
        T* temp = new T[size - 1];
        for (int i = 0; i < index; i++) temp[i] = mas[i];
        for (int i = index + 1; i < size; i++) temp[i - 1] = mas[i];
        delete[] mas;
        mas = temp;
        size--;
    }

    void Output() const {
        for (int i = 0; i < size; i++) cout << mas[i] << "\t";
        cout << endl;
    }
};
