//
// Created by plack on 31.01.2021.
//

#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack(const Stack &other) {

}

Stack::Stack(size_t size) {
    stack = new double[size];
    this->size = size;
    sp = -1;
}

Stack::~Stack() {
    delete[] stack;
}

double Stack::top() {
    if(isEmpty()){
        cout << "Stack is empty\n";
        exit(EXIT_FAILURE);
    } else return stack[sp];
}

void Stack::push(double v) {
    if(isFull()){
        cout << "Stack Overflow\n";
        exit(EXIT_FAILURE);
    } else stack[++sp] = v;
}

void Stack::pop() {
    if(isEmpty()){
        cout << "Stack is empty\n";
        exit(EXIT_FAILURE);
    }else sp--;
}

bool Stack::isFull() {
    return sp == size -1;
}

bool Stack::isEmpty() {
    return sp == -1;
}
