#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); i++) {
        int sum = 0;
        for (string name : photo[i]) {
            sum += m[name];
        }
        answer.push_back(sum);
    }

    return answer;
}