#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    int left = 0, right = 0;
    int sum = sequence[0];
    int len = -1;
    while (1) {
        if (right == n) break;
        if (sum == k) {
            if (len != -1)
                if (len <= right - left) {
                    sum += sequence[++right];
                    continue;
                }
            len = right - left;
            answer.clear();
            answer.push_back(left);
            answer.push_back(right);
            sum += sequence[++right];
        }
        else if (sum > k) {
            sum -= sequence[left++];
        }
        else {
            sum += sequence[++right];
        }
    }
    return answer;
}