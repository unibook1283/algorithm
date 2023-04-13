import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int solution(String[] kor, String[] usa, String[] incs) {
        int answer = -1;
        int[][] count = new int[10001][10001];
        HashMap<String, Integer> map = new HashMap<>();
        int korIndex = 0, usaIndex = 0;
        for (String s : kor) {
            map.put(s, korIndex++);
        }
        for (String s : usa) {
            map.put(s, usaIndex++);
        }

        for (int i=0;i<incs.length;i++) {
            ArrayList<String> korItems = new ArrayList<>();
            ArrayList<String> usaItems = new ArrayList<>();
            String inc = incs[i];
            String[] items = inc.split(" ");
            for (String item : items) {
                if (Arrays.stream(kor).anyMatch(k -> k.equals(item))) {
                    korItems.add(item);
                }
                else {
                    usaItems.add(item);
                }
            }

            for (String k : korItems) {
                int kIndex = map.get(k);
                for (String u : usaItems) {
                    int uIndex = map.get(u);
                    count[kIndex][uIndex]++;
                }
            }
        }

        for (int i=0;i<10001;i++) {
            for (int j=0;j<10001;j++) {
                if (answer < count[i][j]) {
                    answer = count[i][j];
                }
            }
        }

        return answer;
    }
}