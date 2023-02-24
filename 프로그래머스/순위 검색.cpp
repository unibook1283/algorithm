#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;
vector<int> solution(vector<string> info, vector<string> query) {
    m["-"] = 0;
    m["cpp"] = 1;
    m["java"] = 2;
    m["python"] = 3;
    m["backend"] = 1;
    m["frontend"] = 2;
    m["junior"] = 1;
    m["senior"] = 2;
    m["chicken"] = 1;
    m["pizza"] = 2;

    vector<int> List[4][3][3][3];

    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        int arr[4] = { m[a], m[b],m[c],m[d] };

        for (int i = 0; i < (1 << 4); i++) {
            int idx[4] = { 0, };
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) {
                    idx[j] = arr[j];
                }
            }
            List[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    sort(List[i][j][k][l].begin(), List[i][j][k][l].end());
                }
            }
        }
    }
    vector<int> answer;
    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;
        auto& slist = List[m[a]][m[b]][m[c]][m[d]];
        auto low = lower_bound(slist.begin(), slist.end(), score);
        answer.push_back(slist.end() - low);
    }

    return answer;
}