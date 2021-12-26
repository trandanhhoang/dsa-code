//DONE
#include "expression.h"

using namespace std;

/*
 * Phases:
 *  - No precendence: + -
 *  - Precendence, no parentheses: + - * /
 *  - Precendence, parentheses, only left associativity: + - * / ( )
 *  - Precendence, parentheses, left and right associativity: + - * / ^ ( )
 *  ^: right association.
 */

void cal(stack<float> &operands, stack<char> &operators){
    float right = operands.top();
    operands.pop();
    float left = operands.top();
    operands.pop();
    char op = operators.top();
    operators.pop();
    operands.push(calculate(op,left,right));
}

float evaluateInfix(string exp) {
    stack<float> operands;
    stack<char> operators;

    /* Read token and calculate on the fly */
    for (auto&& token : exp) {
        auto kind = getTokenKind(token);
        if (kind == SPACE) {
            continue;
        } else if (kind == OPERAND) {
            // TODO
            operands.push(token-'0');
        } else if (kind == PARENTHESES) {
            // TODO
            if(token == '('){
                operators.push(token);
            }
            else{
                while(operators.top() != '('){
                    cal(operands,operators);
                }
                operators.pop();
            }

        } else if (kind == OPERATOR) {
            // TODO
            //= size thi push vao thoi
            if(operators.size() == 0)
                operators.push(token);
            else{
                if(operators.top() != '('){
                    if(getPrecendence(operators.top()) >= getPrecendence(token) && leftAssociative(token))
                        cal(operands,operators);
                }
                operators.push(token);
            }
        } else {
            throw string("Invalid token ") + string({token});
        }
    }
    while(operators.size() != 0 ){
        cal(operands,operators);
    }

    /* Last token has been parsed */
    // TODO
    return operands.top();
}

int main() {
    /* Testcases */
    auto phase1 = {
        "1 + 2", //3
        "4 - 3", //1
        "1 - 2 - 3 + 4",//0
    };
    auto phase2 = {
        "1 + 2 * 3 * 4 - 5", //20
        "9 - 4 / 2 * 3",//3
    };
    auto phase3 = {
        "2 * (2 + 3)",//10
        "(5 + 7) / (8 - 5)",//4
        "1 + 4 * (4 - 3 * 2)",//-7
        "(7 - 5) * (2 + (4 - 3) * 2)",//8
    };
    auto phase4 = {
        "3 ^ 1 ^ 9",//3^1 = 3
        "5 - 6 + (6 - 8 / (9 - 5) * 2) ^ 2 ^ 3",//
    };

    /* Run test */
    int i = 1;
    for (auto&& phase : {phase1, phase2, phase3, phase4}) {
        cout << "Phase " << i++ << "\n";
        for (auto&& test : phase) {
            try {
                cout << evaluateInfix(test) << "\n";
            } catch (string e) {
                cout << e << "\n";
            }
        }
    }

    return 0;
}
