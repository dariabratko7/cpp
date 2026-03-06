#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
    string m_name;
    int m_age;

public:
    Person() : m_name("Unknown"), m_age(0) {}
    Person(const string& name, int age) : m_name(name), m_age(age) {}

    string GetName() const { return m_name; }
    int GetAge() const { return m_age; }

    void SetName(const string& name) { m_name = name; }
    void SetAge(int age) { m_age = age; }

    void Print() const { cout << m_name << " (" << m_age << ")"; }
};
