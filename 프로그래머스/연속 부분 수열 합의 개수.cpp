#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000 * 1000 + 1;
bool check[MAX];
int solution(vector<int> elements) {
    int answer = 0;
    int total = 0;
    for (int i = 0; i < elements.size(); i++) {
        total += elements[i];
    }
    check[total] = true;

    int n = elements.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n / 2; j++) {
            sum += elements[(i + j) % n];
            check[sum] = true;
            check[total - sum] = true;
        }
    }

    for (int i = 0; i <= total; i++) {
        if (check[i]) answer++;
    }

    return answer;
}