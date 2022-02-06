#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

double performOperation(stack<double>& oprnds, char oprtor) {
    double result = 0.0;
    switch (oprtor) {
    case '+': // 0 + opr1 + opr2 ...
        result = 0.0;
        while (!oprnds.empty()) {
            result += oprnds.top();
            oprnds.pop();
        }
        return result;
    case '-':
        if (oprnds.size() == 1)
            return -oprnds.top(); // -opr1

        result = oprnds.top();
        oprnds.pop();

        while (!oprnds.empty()) {
            result -= oprnds.top();
            oprnds.pop();
        }
        return result; // opr1 - opr2 - opr3 ...
    case '*':
        result = 1.0;
        while (!oprnds.empty()) {
            result *= oprnds.top();
            oprnds.pop();
        }
        return result;
    case '/':
        if (oprnds.size() == 1)
            return 1 / oprnds.top(); // 1/opr1

        result = oprnds.top();
        oprnds.pop();

        while (!oprnds.empty()) {
            result /= oprnds.top();
            oprnds.pop();
        }
        return result; // opr1 / opr2 / opr3 ...
    } // switch-case: here returns; don't forget to break otherwise!
} // unspecified behaviour if operator invalid
int main() {

    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<string> allTokens; // outer stack
    string currentToken;

    while (cin >> currentToken) {
        if (currentToken == ")") {
            stack<double> operands; // inner stack
            while (allTokens.top().size() > 1 || // while operand
                allTokens.top().find_first_of("+-*/") == string::npos) {
                operands.push(stod(allTokens.top()));
                allTokens.pop();
            }
            char oprtor = allTokens.top()[0];
            allTokens.pop();
            allTokens.pop(); // remove oprtor, remove "("
            allTokens.push(to_string(performOperation(operands, oprtor)));
        }
        else {
            allTokens.push(currentToken);
        }
    }
    cout << allTokens.top() << endl;
    return 0;
}