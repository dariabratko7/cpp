#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
#include <iterator>  
using namespace std;

int main() {

    cout << "=== Задача 1: vector<int> з алгоритмами ===\n";
    vector<int> v = { 5, 3, 8, 1, 9, 2 };

    auto min_it = min_element(v.begin(), v.end());
    cout << "Мін значення: " << *min_it << "\n";

    auto max_it = max_element(v.begin(), v.end());
    cout << "Макс значення: " << *max_it << "\n";

    sort(v.begin(), v.end(), greater<int>());
    cout << "Сортування по убыванию: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    sort(v.begin(), v.end());
    cout << "Сортування по зростанню: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
    cout << "Збільшення в 2 раза: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    transform(v.begin(), v.end(), v.begin(), [](int x) { return x / 2; });
    cout << "Зменшення в 2 раза: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    v.erase(remove(v.begin(), v.end(), 3), v.end());
    cout << "Після удаления 3: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";


    cout << "=== Задача 2: динамический массив и vector ===\n";


    unique_ptr<int[]> grades(new int[5] {10, 9, 12, 11, 8});
    int size = 5;

    vector<int> grades_vec(grades.get(), grades.get() + size);


    int exam_grade = 12;

    grades_vec.push_back(exam_grade);

    grades_vec.insert(grades_vec.end(), 11);

    int extra_grade = 10;
    copy(&extra_grade, &extra_grade + 1, back_inserter(grades_vec));


    int another_grade = 9;
    insert_iterator<vector<int>> it(grades_vec, grades_vec.end());
    *it = another_grade;

    int tests[] = { 12,11,12 };
    grades_vec.insert(grades_vec.begin(), tests, tests + 3);

    cout << "Через []: ";
    for (size_t i = 0; i < grades_vec.size(); ++i) cout << grades_vec[i] << " ";
    cout << "\n";

    cout << "Через at(): ";
    for (size_t i = 0; i < grades_vec.size(); ++i) cout << grades_vec.at(i) << " ";
    cout << "\n";

    cout << "Через iterator: ";
    for (auto it = grades_vec.begin(); it != grades_vec.end(); ++it) cout << *it << " ";
    cout << "\n\n";

    cout << "=== Задача 3: list<int> ===\n";
    list<int> grades_list(grades.get(), grades.get() + size);


    grades_list.push_back(12);
    grades_list.insert(grades_list.end(), 11);


    grades_list.insert(grades_list.begin(), tests, tests + 3);


    cout << "list<int> оценки: ";
    for (auto it = grades_list.begin(); it != grades_list.end(); ++it) cout << *it << " ";
    cout << "\n";

    return 0;
}
