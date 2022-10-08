#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    for (int i = 0; i < number.length(); i++) {
        for (int j = 1; j <= k; j++) {
            if (number[i] < number[i + j]) {
                number.erase(i, 1);
                k--;
                i--;
                break;
            }
        }
        if (k <= 0) break;
    }
    if (k > 0) number.erase(number.end() - k);

    return number;
}