//DONE
#include "expression.h"

using namespace std;

/*
    Infix: (((1 + 2) * (3 - 4)) ^ 2) ^ (5 - 2 / (4 / 2)) = 
    Prefix: ^^*+12-342-5/2/42
    Postfix: 12+34-*2^5242//-^
*/

string prefixFromPostfix(string postfix) {
    // TODO
    stack<string> my_stack;
    for(int i = 0;i <  postfix.length();i++){
        if(getTokenKind(postfix[i]) == OPERATOR){
            string right = my_stack.top();
            my_stack.pop(); 
            string left = my_stack.top();
            my_stack.pop();
            // PUSH INTO STACK
            my_stack.push(postfix[i] + left + right);        
        }
        else{
            string operand = string({postfix[i]});
            my_stack.push(operand);
        }
    }

    return my_stack.top();
}
//string prefix = "^^*+12-342-5/2/42";
string postfixFromPrefix(string prefix) {
    stack<string> my_stack;

    for(int i = prefix.length() - 1;i >= 0;i--){
        if(getTokenKind(prefix[i]) == OPERATOR){
            string left = my_stack.top();
            my_stack.pop(); 
            string right = my_stack.top();
            my_stack.pop();
            // PUSH INTO STACK
            my_stack.push(left + right + prefix[i]);        
        }
        else{
            string operand = string({prefix[i]});
            my_stack.push(operand);
        }
    }

    return my_stack.top();
}

int main() {
    string prefix = "^^*+12-342-5/2/42";
    string postfix = "12+34-*2^5242//-^";

    cout << "Prefix : " << prefixFromPostfix(postfix) << "\n";
    cout << "Postfix: " << postfixFromPrefix(prefix) << "\n";

    return 0;
}
