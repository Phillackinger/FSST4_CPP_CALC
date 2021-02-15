//
// Created by plack on 31.01.2021.
//

#ifndef TASCHENRECHNER_STACK_H
#define TASCHENRECHNER_STACK_H


#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <new>
#include <iostream>

using namespace std;

class Stack {
private:
    double *stack{};
    size_t size{};
    size_t sp{};

public:
    explicit Stack(size_t size = 100);

    Stack(const Stack &other);

    ~Stack();

    double top() throw(underflow_error);

    void push(double v) throw(overflow_error);

    void pop() throw(underflow_error);

    bool isFull() const;

    bool isEmpty() const;
};


#endif //TASCHENRECHNER_STACK_H
