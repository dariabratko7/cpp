#include <iostream>
#include <vector>
using namespace std;

int main() {

    int gradesArray[] = { 8, 9, 7, 10, 6 };
    int testArray[] = { 9, 8, 10 };

    int n = sizeof(gradesArray) / sizeof(gradesArray[0]);






    vector<int> grades(gradesArray, gradesArray + n);






    grades.push_back(11);






    grades.insert(grades.begin(), testArray, testArray + (sizeof(testArray) / sizeof(testArray[0])));




    cout << "Вивід через []: ";
    for (size_t i = 0; i < grades.size(); ++i) {
        cout << grades[i] << " ";
    }
    cout << endl;

    cout << "Вивід через at(): ";
    for (size_t i = 0; i < grades.size(); ++i) {
        cout << grades.at(i) << " ";
    }
    cout << endl;

    cout << "Вивід через iterator: ";
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
