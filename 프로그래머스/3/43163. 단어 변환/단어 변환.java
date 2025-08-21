import java.util.*;

class Solution {
    
    Map<String, Integer> voca;
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        voca = new HashMap<>();
        
        voca.put(begin, 0);
        for(int i = 0; i < words.length; i++) {
            voca.put(words[i], -1);
        }
        
        if(!voca.containsKey(target)) {
            return 0;
        }
        
        Queue<String> q = new ArrayDeque<>();
        q.offer(begin);
        
        while(!q.isEmpty()) {
            String cur = q.poll();
            
            for(String key : voca.keySet()) {
                if(voca.get(key) != -1) continue;
                
                if(connect(cur, key)) {
                    if(cur.equals(target)) {
                        return voca.get(cur) + 1;
                    }
                    voca.put(key, voca.get(cur) + 1); 
                    q.offer(key);
                }
            }
        }
        
        answer = voca.get(target) == -1 ? 0 : voca.get(target);
        
        return answer;
    }
    
    boolean connect(String a, String b) {
        int count = 0;
        for(int i = 0; i < a.length(); i++) {
            if(a.charAt(i) != b.charAt(i)) count++;
        }
        return count == 1;
    }
}