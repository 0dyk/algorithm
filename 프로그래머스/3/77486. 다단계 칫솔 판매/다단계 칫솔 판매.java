import java.util.*;

class Solution {
    
    static Map<String, String> father;
    static Map<String, Integer> money;
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        father = new HashMap<>();
        money = new HashMap<>();
        
        for(int i = 0; i < enroll.length; ++i) {
            father.put(enroll[i], referral[i].equals("-") ? "center" : referral[i]);
            money.put(enroll[i], 0);
        }
        
        for(int i = 0; i < seller.length; ++i) {
            
            String cur = seller[i];
            int value = amount[i] * 100;

            while(value > 0 && !cur.equals("center")) {
                money.put(cur, (money.get(cur) + value - value / 10));
                value /= 10;
                
                cur = father.get(cur);
            }
        }
        
        for(int i = 0; i < enroll.length; ++i) {
            answer[i] = money.get(enroll[i]);
        }
        
        return answer;
    }
}