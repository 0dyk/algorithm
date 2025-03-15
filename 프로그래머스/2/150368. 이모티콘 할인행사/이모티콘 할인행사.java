import java.util.*;

class Solution {
    
    static int[] sale;
    static int[][] _users;
    static int[] _emoticons;
    static int[] answer;
    
        
    static void simul() {
        int count = 0;
        int totalSum = 0;
        
        for(int[] user : _users) {
            int sum = 0;
            for(int i = 0; i < _emoticons.length; ++i) {
                int tmp = _emoticons[i] * (100 - sale[i]) / 100;
                
                // 구매
                if(user[0] <= sale[i]) {
                    sum += tmp;
                }
            }
            
            if(sum >= user[1]) {
                count++;
            }
            else {
                totalSum += sum;
            }
        }
        
        if(count > answer[0] || (count == answer[0] && totalSum > answer[1])) {
            answer[0] = count;
            answer[1] = totalSum;
        }
    }
    
    static void combi(int idx) {
        if(idx == sale.length) {
            simul();
            return;
        }
        
        int k = 10;
        while(k <= 40) {
            sale[idx] = k;
            combi(idx + 1);
            k += 10;
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        _users = users;
        _emoticons = emoticons;
        answer = new int[2];
        
        sale = new int[emoticons.length];
        combi(0);

        return answer;
    }
}