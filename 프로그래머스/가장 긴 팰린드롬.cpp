#include <iostream>
#include <string>
using namespace std;
int odd_longest_palindrome(string s, int index) {
    int left = index;
    int right = index;
    int maxi = 0;
    while (left >= 0 && right < s.length()) {
        if (s[left] != s[right]) break;
        maxi = max(maxi, right - left + 1);
        left--; right++;
    }
    return maxi;
}
int even_longest_palindrome(string s, int index) {
    int left = index;
    int right = index + 1;
    int maxi = 0;
    while (left >= 0 && right < s.length()) {
        if (s[left] != s[right]) break;
        maxi = max(maxi, right - left + 1);
        left--; right++;
    }
    return maxi;
}int solution(string s)
{
    int answer = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        answer = max(answer, odd_longest_palindrome(s, i));
        answer = max(answer, even_longest_palindrome(s, i));
    }

    return answer;
}