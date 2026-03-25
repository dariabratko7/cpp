#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;


class MyException : public exception {
protected:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class EmptyListException : public MyException {
public:
    EmptyListException() : MyException("Помилка: список порожній!") {}
};

class MemoryException : public MyException {
public:
    MemoryException() : MyException("Помилка: нестача пам'яті!") {}
};

class MathException : public MyException {
public:
    MathException(const string& msg) : MyException(msg) {}
};

class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Помилка: ділення на нуль!") {}
};

class FileException : public MyException {
public:
    FileException(const string& msg) : MyException(msg) {}
};

class FileOpenException : public FileException {
public:
    FileOpenException() : FileException("Помилка: не вдалося відкрити файл!") {}
};

#endif
