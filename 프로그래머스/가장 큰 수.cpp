#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(int u, int v) {
    return to_string(u) + to_string(v) > to_string(v) + to_string(u);
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0) return "0";
    //if (numbers[0] == '0') return "0";
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}