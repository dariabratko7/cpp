#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;
    double average;

    Student(string name, int age, double average) {
        this->name = name;
        this->age = age;
        this->average = average;
    }

    void show() {
        cout << name << " " << age << " " << average << endl;
    }
};

class Group {
public:
    string groupName;
    vector<Student*> students;

    Group(string name) {
        groupName = name;
    }

    void addStudent(Student* s) {
        students.push_back(s);
    }

    void showStudents() {
        cout << "Group: " << groupName << endl;
        for (Student* s : students) {
            s->show();
        }
    }
};

int main() {

    Student s1("Ivan", 18, 90);
    Student s2("Olga", 19, 85);

    Group g("CS-101");

    g.addStudent(&s1);
    g.addStudent(&s2);

    g.showStudents();

    return 0;
}