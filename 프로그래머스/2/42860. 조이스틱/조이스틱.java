import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int move = name.length();
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < name.length(); ++i) {
            int a = name.charAt(i) - 'A';
            int b = 'Z' - name.charAt(i) + 1;
            
            answer += a > b ? b : a;

            int idx = i + 1;
            
            while(idx < name.length() && name.charAt(idx) == 'A') {
                idx++;
            }
            
            move = Math.min(move, i * 2 + name.length() - idx);
            move = Math.min(move, (name.length() - idx) * 2 + i);    
        }

        answer += move;

        return answer;
    }
}