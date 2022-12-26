#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Page {
    int idx;
    int basic, link;
    double score;
};

bool cmp(Page u, Page v) {
    if (u.score == v.score)
        return u.idx < v.idx;
    return u.score > v.score;
}
int solution(string word, vector<string> pages) {
    int wsize = word.size();
    map<string, int> pagehash;
    vector<Page> pagelist;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for (int i = 0; i < pages.size(); i++) {
        string s = pages[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int mid = 0, posl = 0, posr;
        while (mid <= posl) {
            posl = s.find("<meta", posl + 1);
            posr = s.find(">", posl);
            mid = s.rfind("https://", posr);
        }
        posr = s.find("\"", mid);
        string url = s.substr(mid, posr - mid);

        posl = s.find("<body>", posr);
        int basic = 0;
        for (int start = posl;;) {
            start = s.find(word, start + 1);
            if (start == -1) break;
            if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize])) {
                basic++;
                start += wsize;
            }
        }

        int link = 0;
        for (int start = posl;;) {
            start = s.find("<a href", start + 1);
            if (start == -1) break;
            link++;
        }

        pagehash[url] = i;
        pagelist.push_back({ i, basic, link, (double)basic });
    }

    for (int i = 0; i < pages.size(); i++) {
        string s = pages[i];
        for (int posl = 0, posr = 0;;) {
            posl = s.find("<a href", posr);
            if (posl == -1) break;

            posl = s.find("https://", posl);
            posr = s.find("\"", posl);
            string url = s.substr(posl, posr - posl);

            auto it = pagehash.find(url);
            if (it != pagehash.end()) {
                pagelist[it->second].score += (double)pagelist[i].basic / pagelist[i].link;
            }
        }
    }

    sort(pagelist.begin(), pagelist.end(), cmp);
    return pagelist[0].idx;
}