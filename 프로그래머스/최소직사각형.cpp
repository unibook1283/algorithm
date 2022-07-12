#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxl = 0;
    int maxs = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int longer = max(sizes[i][0], sizes[i][1]);
        int shorter = min(sizes[i][0], sizes[i][1]);
        maxl = max(maxl, longer);
        maxs = max(maxs, shorter);
    }
    answer = maxl * maxs;

    return answer;
}