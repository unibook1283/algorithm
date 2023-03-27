#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int duration;
string name, melody;
void calDuration(string start, string end) {
    int s = 60 * stoi(start.substr(0, 2)) + stoi(start.substr(3));
    int e = 60 * stoi(end.substr(0, 2)) + stoi(end.substr(3));
    duration = e - s;
}
void parseInfo(string info) {
    stringstream ss(info);
    string start, end;
    getline(ss, start, ',');
    getline(ss, end, ',');
    getline(ss, name, ',');
    getline(ss, melody, ',');
    calDuration(start, end);
}
void replaceAll(string& s, string from, string to) {
    int pos;
    while (1) {
        pos = s.find(from);
        if (pos == -1) break;
        s.replace(pos, 2, to);
    }
}
void transformMelodyForm(string& s) {
    replaceAll(s, "C#", "c");
    replaceAll(s, "D#", "d");
    replaceAll(s, "F#", "f");
    replaceAll(s, "G#", "g");
    replaceAll(s, "A#", "a");
}
string adjustLengthOfMelody(string& melody) {
    string ret;
    for (int i = 0; i < duration; i++) {
        ret += melody[i % melody.size()];
    }
    return ret;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<pair<int, int>, string>> candidates;

    transformMelodyForm(m);
    for (int i = 0; i < musicinfos.size(); i++) {
        string info = musicinfos[i];
        parseInfo(info);
        transformMelodyForm(melody);
        melody = adjustLengthOfMelody(melody);
        if (melody.find(m) != -1) {
            candidates.push_back({ {-duration, i}, name });
        }
    }
   
    if (candidates.empty()) {
        return "(None)";
    }
    
    sort(candidates.begin(), candidates.end());
    answer = candidates.front().second;

    return answer;
}