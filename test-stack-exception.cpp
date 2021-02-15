#include <stdio.h>
#include <cstdio>
#include <cstdlib> // size_t
#include <iostream>

using namespace std;

#include <new>          // !!!!!!!!!! std::bad_alloc
#include <stdexcept>    // !!!!!!!!!! std::out_of_range
// !!!!!!!!!! std::overflow_error
// !!!!!!!!!! std::underflow_error
#include "stack.h"      //Die eigene Klasse Stack

// ---------------------------------------------------------------------
int main() {
    Stack stack(5);
    cout << "*** Test 1: top mit leerem stack ..." << endl;

    try {
        double v = stack.top();
    } catch (underflow_error &ex) {
        cerr << ex.what() << endl;
    }

    cout << "*** Test 2: Stack Überlauf ..." << endl;

    try {
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);

    } catch (overflow_error &ex) {
        cerr << ex.what() << endl;

    }
    return 0;
}

