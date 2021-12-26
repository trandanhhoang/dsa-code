// DONE !!!
#include "expression.h"

using namespace std;

/*
Infix: 5 * (8 - 3 * 2) ^ 2 ^ 3 = 1280
Expression tree:

              *
            /  \
          5     ^
               / \
             /    \
           -      ^
         /  \    / \
       8     *  2   3
           /  \
         3     2

Prefix: *5^-8*32^23
Postfix: 5832*-23^^*

*/

/* For simplicity, operand has only one character */

float evaluatePrefix(string exp) {
    // TODO
    stack<float> my_stack;
    int length = exp.length();
    for(int i = length;i >= 0 ;i--){
      if(getTokenKind(exp[i]) == OPERATOR){
        float left = my_stack.top();
        my_stack.pop(); 
        float right = my_stack.top();
        my_stack.pop();
        my_stack.push(calculate(exp[i],left,right));
      }
      else{
        my_stack.push(exp[i] - '0');
      }
    }
    return my_stack.top();
}

float evaluatePostfix(string exp) {
    // TODO
    stack<float> my_stack;
    int length = exp.length();
    // POP 2 element
    for(int i = 0;i < length;i++){
      if(getTokenKind(exp[i]) == OPERATOR){
        float right = my_stack.top();
        my_stack.pop(); 
        float left = my_stack.top();
        my_stack.pop();
        // PUSH INTO STACK
        my_stack.push(calculate(exp[i],left,right));        
      }
      else{
        my_stack.push(exp[i] - '0');
      }
    }
    return my_stack.top();
}
// 2^3^4 => 2^(3^4) = ... INFIX
//586
//528^
//5256*

int main() {
    string prefix = "*5^-8*32^23";
    string postfix = "5832*-23^^*";

    cout << evaluatePrefix(prefix) << "\n";
    cout << evaluatePostfix(postfix) << "\n";

    return 0;
}
