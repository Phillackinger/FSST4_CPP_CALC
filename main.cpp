#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

#define IL_MAX 20
#define END_CHAR '='

#include "stack.h"


char mygetline(char str[], int len ){
    scanf("%s", str);
    if(isdigit(str[0])) return('0');
    else return(str[0]);
}

int main(){
    double op1, op2;  // hold an operand of an expression
    char input_line[IL_MAX+1]; //input line
    char ch; //hold return value of mygetline()

    Stack stack(1024); // stack with max. 1024 Values

    cout << "\nTaschenrechenr...";
    cout << " \nTaschenrechner ...";
    cout << " \nZahlen in umgekehrter polnischer Notation eingeben.";
    cout << " \n ... Beispiel: 12 2 * 4 + 2 / = ";
    cout << " \n ... dies entspricht infix: (12 * 2 + 4) / =";
    cout << " \n ... Ergebnis=14.00 \n\n";

    do{
        ch=mygetline(input_line, IL_MAX);

        //stack.push(0.0);

        switch(ch){
            case '+':
                op1 = stack.top(); stack.pop();
                op2 = stack.top(); stack.pop();
                stack.push(op1+op2);
                break;
            case '-':
                op1 = stack.top(); stack.pop();
                op2 = stack.top(); stack.pop();
                stack.push(op1-op2);
                break;
            case '*':
                op1 = stack.top(); stack.pop();
                op2 = stack.top(); stack.pop();
                stack.push(op1*op2);
                break;
            case '/':
                op2 = stack.top(); stack.pop();
                if(op2 == 0.0) {
                    cerr << "\nDivision durch 0 nicht definiert!\n";
                    stack.pop();
                }else{
                    op1 = stack.top(); stack.pop();
                    stack.push(op1/op2);
                }
                break;
            case '0':
                stack.push(atof(input_line));
                break;
            case '=':
                cout.precision(2);
                cout << "\nErgebnis = " << stack.top() << endl;
                break;
        }
    } while(input_line[0] !='=');

    return 0;
}

