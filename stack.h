//
// Created by plack on 31.01.2021.
//

#ifndef TASCHENRECHNER_STACK_H
#define TASCHENRECHNER_STACK_H


#include <c++/4.8.3/cstdio>

class Stack {
private:
    double* stack{};
    size_t size{};
    size_t sp{};

public:
    explicit Stack(size_t size=100);
    Stack(const Stack& other);
    ~Stack();

    double top();
    void push(double v);
    void pop();

    bool isFull();
    bool isEmpty();
};


#endif //TASCHENRECHNER_STACK_H
