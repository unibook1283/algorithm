#include <string>
#include <vector>
#include <list>
using namespace std;
string to_lower(string s) {
    string ret;
    for (int i = 0; i < s.length(); i++) {
        ret += tolower(s[i]);
    }
    return ret;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0) return 5 * cities.size();
    list<string> cache;
    for (int i = 0; i < cities.size(); i++) {
        string city = to_lower(cities[i]);
        bool hit = false;
        for (auto iter = cache.begin(); iter != cache.end(); iter++) {
            // cache hit
            if (*iter == city) {
                cache.erase(iter);
                cache.push_back(city);
                answer++;
                hit = true;
                break;
            }
        }
        // cache miss
        if (!hit) {
            if (cache.size() == cacheSize) {
                cache.pop_front();
            }
            answer += 5;
            cache.push_back(city);
        }
    }
    return answer;
}