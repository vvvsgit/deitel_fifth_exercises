#include <iostream>
#include <cstring>
#include <stack>

bool isOperator(const char);
int precedence(const char, const char);
void convertToPostfix(char *, char *);
int evaluatePostfixExpression(char *);
int calculate(const int, const char, const int);

int
main()
{
    std::cout << std::endl;
    
    char expression[] = "(6+2)*5-8/4";// = 38
    char infix[strlen(expression + 2)];
    int i;
    for (i = 0; expression[i] != '\0'; ++i) {
        infix[i] = expression[i];
    }
    infix[i] = ')';
    infix[++i] = '\0';
    char postfix[strlen(infix)];

    convertToPostfix(infix, postfix);
    std::cout << infix << std::endl << postfix << std::endl;
    std::cout << std::endl;

    std::cout << evaluatePostfixExpression(postfix) << std::endl;

    std::cout << std::endl;
    return 0;
}

bool
isOperator(const char o)
{
    return o == '+' || o == '-' || o == '*' || o == '/' || o == '%';
}

int
precedence(const char one, const char two)
{
    if ((one == '+' || one == '-') && (two == '+' || two == '-')) {
        return 0;
    }
    if ((one == '+' || one == '-') && (two != '+' || two != '-')) {
        return -1;
    }
    return 1;
}

void
convertToPostfix(char *infix, char *postfix)
{
    std::stack<char> tool;
    tool.push('(');

    int infixIndex = 0;
    int postfixIndex = 0;
    while (!tool.empty()) {
        if (infix[infixIndex] >= '0' && infix[infixIndex] <= '9') {
            postfix[postfixIndex] = infix[infixIndex];
            ++postfixIndex;
            ++infixIndex;
        }
        if (infix[infixIndex] == '(') {
            tool.push(infix[infixIndex]);
            ++infixIndex;
        }
        if (isOperator(infix[infixIndex])) {
            while (isOperator(tool.top())) {
                if (precedence(infix[infixIndex], tool.top()) <= 0) {
                    postfix[postfixIndex] = tool.top();
                    tool.pop();
                    ++postfixIndex;
                } else { break; }
            }
            tool.push(infix[infixIndex]);
            ++infixIndex;
        }
        if (infix[infixIndex] == ')') {
            ++infixIndex;
            while (tool.top() != '(') {
                postfix[postfixIndex] = tool.top();
                ++postfixIndex;
                tool.pop();
            }
            tool.pop();
        }
    }
    postfix[postfixIndex] = '\0';
}

int
evaluatePostfixExpression(char *postfix)
{
    std::stack<int> tool;
    for (int i = 0; postfix[i] != '\0'; ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            tool.push(postfix[i] - '0');
        } else {
            int x = tool.top();
            tool.pop();
            int y = tool.top();
            tool.pop();
            tool.push(calculate(y, postfix[i], x));
        }
    }
    return tool.top();
}

int
calculate(const int op1, const char op, const int op2)
{
    if (op == '+') {
        return op1 + op2;
    } else if (op == '-') {
        return op1 - op2;
    } else if (op == '*') {
        return op1 * op2;
    } else if (op == '/') {
        return op1 / op2;
    }
    return op1 % op2;
}

