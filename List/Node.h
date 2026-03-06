#pragma once

template <typename T>
class Node
{
private:
    T m_data;           // Інкапсульовані дані
    Node* m_next;

public:
    Node(const T& data) : m_data(data), m_next(nullptr) {}

    T GetData() const { return m_data; }
    void SetData(const T& data) { m_data = data; }

    Node* GetNext() const { return m_next; }
    void SetNext(Node* next) { m_next = next; }
};
