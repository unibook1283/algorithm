#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;
bool d[10000000];
bool check[7];
void go(string numbers, int n) {
    d[n] = true;
    for (int i = 0; i < numbers.size(); i++) {
        if (!check[i]) {
            int number = numbers[i] - '0';
            check[i] = true;
            go(numbers, n * 10 + number);
            check[i] = false;
        }
    }
}
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    go(numbers, 0);
    for (int i = 2; i < 10000000; i++) {
        if (d[i]) {
            if (is_prime(i)) answer++;
        }
    }

    return answer;
}