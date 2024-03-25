#include <iostream>
#include <string>
using namespace std;

string expression;
int alphabet_value[6];
int max_value = 0;

int calcExpr() {
    int result = alphabet_value[expression[0] - 'a'];

    int idx = 1;
    while(idx < expression.length()) {
        char operation = expression[idx];
        int operand = alphabet_value[expression[idx + 1] - 'a'];

        if (operation == '-') {
            result -= operand;
        }
        else if (operation == '+') {
            result += operand;
        }
        else if (operation == '*') {
            result *= operand;
        }

        idx += 2;
    }

    return result;
}

void setValue(int idx) {
    if (idx == 6) {
        max_value = max(max_value, calcExpr());
        return;
    }

    for (int i = 1; i <= 4; i++) {
        alphabet_value[idx] = i;
        setValue(idx + 1);
    }
}

int main() {
    cin >> expression;

    setValue(0);

    cout << max_value;

    return 0;
}