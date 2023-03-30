#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[110];
int myChild[110]; // 해당 node의 몇 번째 index의 child가 실선인지. 그 index.
vector<int> ballsAtNode[110]; // node에 쌓여있는 숫자들
vector<int> answer;
void fallTheBall(int here, int ballNumber) {
    if (graph[here].empty()) {
        ballsAtNode[here].push_back(ballNumber);
        return;
    }
    int next = graph[here][myChild[here]];
    myChild[here] = (myChild[here] + 1) % graph[here].size();
    fallTheBall(next, ballNumber);
}
bool isFinished(vector<int> target) {
    for (int i = 0; i < target.size(); i++) {
        if (!graph[i + 1].empty()) continue; // leaf node가 아니면 continue
        if (ballsAtNode[i + 1].size() * 3 < target[i])
            return false;
    }
    return true;
}
vector<int> errorResult() {
    vector<int> ret;
    ret.push_back(-1);
    return ret;
}
vector<int> makeBallNumberArray(int target, int bucketSize) {
    if (target < bucketSize || bucketSize * 3 < target) {
        return errorResult();
    }
    vector<int> bucket(bucketSize, 1);
    int usedBallCount = bucketSize;
    int index = bucketSize - 1;
    while (index >= 0 && usedBallCount < target) {
        while (usedBallCount < target && bucket[index] < 3) {
            bucket[index]++;
            usedBallCount++;
        }
        index--;
    }
    return bucket;
}
void getResult(vector<int> target) {
    vector<int> ballNumberArray;
    for (int i = 0; i < target.size(); i++) {
        if (target[i] == 0 && ballsAtNode[i + 1].empty()) continue;
         ballNumberArray = makeBallNumberArray(target[i], ballsAtNode[i + 1].size());
         if (ballNumberArray[0] == -1) {
             answer = ballNumberArray; // errorResult
             return;
         }
         for (int j = 0; j < ballsAtNode[i + 1].size(); j++) {
             answer[ballsAtNode[i + 1][j]] = ballNumberArray[j];
         }
    }
}
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        graph[from].push_back(to);
    }

    int ballNumber = 0;
    while (1) {
        if (isFinished(target)) {
            break;
        }
        fallTheBall(1, ballNumber++);
    }

    answer.resize(ballNumber);
    getResult(target);

    return answer;
}