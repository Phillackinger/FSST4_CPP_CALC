//
// Created by plack on 31.01.2021.
//

#include "stack.h"
#include <cstdlib>
#include <stdexcept>
#include <new>
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

double Stack::top() throw(underflow_error) {
    if (isEmpty()) {
        ostringstream oErr;
        oErr << __FILE__ << ":" << __LINE__ << ":ERROR: underflow_error ";
        oErr << "sp= " << this->sp << " size= " << size << endl;
        throw underflow_error(oErr.str());
    } else return stack[sp];
}

void Stack::push(double v) throw(overflow_error) {
    if (isFull()) {
        ostringstream oErr;
        oErr << __FILE__ << ":" << __LINE__ << ":ERROR: overflow_error ";
        oErr << "sp= " << this->sp << " size= " << size << endl;
        throw overflow_error(oErr.str());
    } else stack[++sp] = v;
}

void Stack::pop() throw(underflow_error) {
    if (isEmpty()) {
        ostringstream oErr;
        oErr << __FILE__ << ":" << __LINE__ << ":ERROR: underflow_error ";
        oErr << "sp= " << this->sp << " size= " << size << endl;
        throw underflow_error(oErr.str());
    } else sp--;
}

bool Stack::isFull() const {
    return sp == size - 1;
}

bool Stack::isEmpty() const {
    return sp == -1;
}
