#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string cleanWord(const string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c) || isdigit(c)) {
            result += tolower(c);
        }
    }
    return result;
}

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Помилка відкриття файлу: " << inputFileName << endl;
        return 1;
    }

    map<string, int> wordFreq;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordFreq[word]++;
            }
        }
    }
    inputFile.close();


    cout << "Слова та їх частоти:" << endl;
    for (const auto& pair : wordFreq) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string mostFrequentWord;
    int maxCount = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    cout << "\nНайчастіше слово: " << mostFrequentWord
        << " (з'являється " << maxCount << " разів)" << endl;

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Помилка створення файлу: " << outputFileName << endl;
        return 1;
    }

    outputFile << "Слова та їх частоти:" << endl;
    for (const auto& pair : wordFreq) {
        outputFile << pair.first << " : " << pair.second << endl;
    }
    outputFile << "\nНайчастіше слово: " << mostFrequentWord
        << " (з'являється " << maxCount << " разів)" << endl;

    outputFile.close();
    cout << "\nРезультати записані у файл: " << outputFileName << endl;

    return 0;
}