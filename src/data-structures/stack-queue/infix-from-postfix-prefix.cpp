//DONE
#include "expression.h"

using namespace std;

//GG INTERVIEW

//AVL. just querry, no delete -> for make dictionary
// AVL -> get height// 
// AVL -> get balanced //
//AVL : insert 1 phep quay(all case). IMPORTANT
//AVL: DELETE. quay tai cha-con-ong-chau-> dinh?(tuy` case). IMPORTANT

// BTREE -> UNROLL -> MUON + MERGE.

// RED - BLACK TREE (BTREE): 
// RESEARCH. bo dinh thoi - completely fair schedule
// insert - 1 quay ?
// delele - ko nhieu lam.

// MIN PARENTHELES
/*
    Postfix: 12+34-*2^5242//-^
    => can 2 dau ngoac quan trong
    Infix: (((1 + 2) * (3 - 4)) ^ 2) ^ (5 - 2 / (4 / 2))      */
void cal(stack<op_and_exp> &my_stack, char op){
    op_and_exp right = my_stack.top();
    my_stack.pop(); 
    op_and_exp left = my_stack.top();
    my_stack.pop();

    if(left.op){
        int left_op = getPrecendence(left.op);
        int now_op = getPrecendence(op);
        if(left_op < now_op || left_op == now_op && !leftAssociative(op)){
            left.exp = "(" + left.exp + ")";
        }
    }
    if(right.op){
        int right_op = getPrecendence(right.op);
        int now_op = getPrecendence(op);
        if(right_op < now_op || right_op == now_op && leftAssociative(op)){
            right.exp = "(" + right.exp + ")";
        }
    }
        
    my_stack.push(op_and_exp(op,left.exp + op + right.exp));
}
string infixFromPostfix(string postfix) {
    stack<op_and_exp> my_stack; // new struct in expression.h
    for(int i = 0;i <  postfix.length();i++){
        if(getTokenKind(postfix[i]) == OPERATOR){
            cal(my_stack,postfix[i]);
        }
        else{
            my_stack.push(op_and_exp(postfix[i]));
        }
    }

    return (my_stack.top()).exp;
}
/*
    Prefix: -+1^2^23/*346
    => ko can dau ngoac nao het
    Infix: 1 + 2 ^ 2 ^ 3 - 3 * 4 / 6 */
string infixFromPrefix(string prefix) {
    // TODO
    return "hihi";
}

int main() {
    // string postfix = "12+34-*2^5242//-^";
    string postfix = "23^45^^";

    string prefix = "-+1^2^23/*346";

    cout << infixFromPostfix(postfix) << "\n";
    // cout << infixFromPrefix(prefix) << "\n";

    return 0;
}

