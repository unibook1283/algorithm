class Solution {
    public int solution(String number) {
        int answer = 0;
        boolean finish = false;
        for (int i=0;i<number.length() - 1;i++) {
            if (number.charAt(i) != '0' && ((number.charAt(i) + 1 - '0') % 10 == number.charAt(i+1) - '0')) {
                answer++;
                i++;
                if (i == number.length() - 1) {
                    finish = true;
                }
            }
            else {
                if (number.charAt(i) == '0') {
                    answer++;
                }
                else {
                    answer+=2;
                }
            }
        }

        if (!finish) {
            if (number.charAt(number.length() - 1) == '0') {
                answer++;
            }
            else {
                answer+=2;
            }
        }

        return answer;
    }
}