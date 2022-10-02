#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dic;
    for (int i = 0; i < 26; i++) {
        string s;
        s += 'A' + i;
        dic.push_back(s);
    }

    for (int i = 0; i < msg.length(); i++) {
        int dsize = dic.size();
        int len = 0;
        int index = 0;
        for (int j = 0; j < dsize; j++) {
            if (dic[j].length() > len) {
                if (msg.substr(i, dic[j].length()) == dic[j]) {
                    len = dic[j].length();
                    index = j;
                }
            }
        }
        if (len != 0) {
            answer.push_back(index + 1);
            if (i < msg.length() - 1) {
                dic.push_back(msg.substr(i, dic[index].length() + 1));
            }
            i += len - 1;
        }
    }

    return answer;
}