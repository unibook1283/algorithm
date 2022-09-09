#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int park[10000];
int sum[10000];

int to_minute(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3));
    return 60 * hour + minute;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<int, int> m, total;

    for (int i = 0; i < records.size(); i++) {
        string time = records[i].substr(0, 5);
        int num = stoi(records[i].substr(6, 4));
        string io = records[i].substr(11);

        int minute = to_minute(time);
        if (io == "IN") {
            m[num] = minute;
        }
        else {
            total[num] += minute - m[num];
            m[num] = -1;
        }
    }
    int end_time = to_minute("23:59");
    for (auto p : m) {
        int num = p.first;
        int minute = p.second;
        cout << minute << '\n';
        if (minute != -1) total[num] += end_time - minute;
        if (total[num] <= fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            int additional = total[num] - fees[0];
            additional += fees[2] - 1;
            additional /= fees[2];
            cout << additional << '\n';
            answer.push_back(fees[1] + additional * fees[3]);
        }
    }

    return answer;
}