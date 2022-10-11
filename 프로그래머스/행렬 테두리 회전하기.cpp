#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_op(vector<char> ops, char ch) {
    for (int i = 0; i < 3; i++) {
        if (ops[i] == ch) return true;
    }
    return false;
}
long long cal(long long a, long long b, char op) {
    if (op == '*') return a * b;
    else if (op == '+') return a + b;
    else return a - b;
}
long long solution(string expression) {
    long long answer = 0;
    vector<char> operators = { '*','+','-' };

    vector<long long> nums;
    vector<char> ops;
    int prev = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (is_op(operators, expression[i])) {
            nums.push_back(stoll(expression.substr(prev, i)));
            ops.push_back(expression[i]);
            prev = i + 1;
        }
    }
    nums.push_back(stoll(expression.substr(prev)));

    do {
        vector<long long> temp_nums = nums;
        vector<char> temp_ops = ops;
        for (int i = 0; i < 3; i++) {
            char op = operators[i];
            for (int j = 0; j < temp_ops.size(); j++) {
                if (op == temp_ops[j]) {
                    long long first = temp_nums[j];
                    long long second = temp_nums[j + 1];
                    long long res = cal(first, second, op);
                    temp_nums[j] = res;
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_ops.erase(temp_ops.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    } while (next_permutation(operators.begin(), operators.end()));
    return answer;
}