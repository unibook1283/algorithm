#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> ranks;

    for (int i = 0; i < players.size(); i++) {
        ranks[players[i]] = i;
    }

    for (string calling : callings) {
        int rank = ranks[calling];
        string inFront = players[rank - 1];
        ranks[calling]--;
        players[rank - 1] = calling;
        ranks[inFront]++;
        players[rank] = inFront;
    }

    for (int i = 0; i < players.size(); i++) {
        answer.push_back(players[i]);
    }

    return answer;
}