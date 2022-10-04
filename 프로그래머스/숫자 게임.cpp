#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int a_index = 0;
    for (int i = 0; i < n; i++) {
        if (A[a_index] < B[i]) {
            a_index++;
        }
    }

    return a_index;
}