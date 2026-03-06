#include "List.h"

template <typename T>
void List<T>::Add(const T & data)
{
    Node<T>* newNode = new Node<T>(data);

    if (!m_head)
    {
        m_head = newNode;
    }
    else
    {
        Node<T>* temp = m_head;
        while (temp->GetNext()) temp = temp->GetNext();
        temp->SetNext(newNode);
    }
    ++m_size;
}

template <typename T>
void List<T>::Print() const
{
    Node<T>* temp = m_head;
    while (temp)
    {
        temp->GetData().Print();
        cout << " -> ";
        temp = temp->GetNext();
    }
    cout << "NULL\n";
}

template <typename T>
void List<T>::RemoveHead()
{
    if (!m_head) return;

    Node<T>* temp = m_head;
    m_head = m_head->GetNext();
    delete temp;
    --m_size;
}

template <typename T>
void List<T>::RemoveAll()
{
    while (m_head) RemoveHead();
}

template <typename T>
void List<T>::Assign(const List& other)
{
    RemoveAll();
    Node<T>* temp = other.m_head;
    while (temp)
    {
        Add(temp->GetData());
        temp = temp->GetNext();
    }
}

template <typename T>
void List<T>::Insert(const T& data, unsigned int index)
{
    if (index > m_size) return;

    Node<T>* newNode = new Node<T>(data);

    if (index == 0)
    {
        newNode->SetNext(m_head);
        m_head = newNode;
    }
    else
    {
        Node<T>* temp = m_head;
        for (unsigned int i = 0; i < index - 1; ++i) temp = temp->GetNext();
        newNode->SetNext(temp->GetNext());
        temp->SetNext(newNode);
    }
    ++m_size;
}

template <typename T>
void List<T>::RemoveAt(unsigned int index)
{
    if (index >= m_size || !m_head) return;

    if (index == 0)
    {
        RemoveHead();
        return;
    }

    Node<T>* temp = m_head;
    for (unsigned int i = 0; i < index - 1; ++i) temp = temp->GetNext();

    Node<T>* toDelete = temp->GetNext();
    temp->SetNext(toDelete->GetNext());
    delete toDelete;
    --m_size;
}
