#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool is_prefix(string s, int s_len, string l) {
    if (s == l.substr(0, s_len)) return true;
    return false;
}
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (is_prefix(phone_book[i], phone_book[i].size(), phone_book[i + 1]))
            return false;
    }
    return true;
}