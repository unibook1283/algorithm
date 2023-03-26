#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int duration;
string name, melody;
string notes[12] = { "C#", "D#", "F#", "G#", "A#", "C", "D", "E", "F", "G", "A", "B" };
int stringTimeToInt(string time) {
    stringstream ss(time);
    int hour, minute;
    char temp;
    ss >> hour >> temp >> minute;
    return 60 * hour + minute;
}
int calDuration(string start, string end) {
    return stringTimeToInt(end) - stringTimeToInt(start);
}
void parseInfo(string info) {
    stringstream ss(info);
    string start, end;
    getline(ss, start, ',');
    getline(ss, end, ',');
    getline(ss, name, ',');
    getline(ss, melody, ',');
    duration = calDuration(start, end);
}
string transformMelodyForm(string melody) {
    for (int i = 0; i < 12; i++) {
        string note = notes[i];
        while (1) {
            int index = melody.find(note);
            if (index == -1) break;
            char ch = 'a' + i;
            string s;
            s += ch;
            melody.replace(index, note.length(), s);
        }
    }
    return melody;
}
string adjustLengthOfMelody(string melody) {
    string ret;
    for (int i = 0; i < duration; i++) {
        ret += melody[i % melody.size()];
    }
    return ret;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<pair<int, int>, string>> candidates;

    for (int i = 0; i < musicinfos.size(); i++) {
        string info = musicinfos[i];
        parseInfo(info);
        melody = transformMelodyForm(melody);
        melody = adjustLengthOfMelody(melody);
        m = transformMelodyForm(m);
        if (melody.find(m) != -1) {
            candidates.push_back({ { -duration, i} , name });
        }
    }

    if (candidates.empty()) {
        return "(None)";
    }

    sort(candidates.begin(), candidates.end());
    answer = candidates.front().second;

    return answer;
}