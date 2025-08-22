import java.util.*;

class Solution {
    
    TreeMap<Integer, Integer> m;
    
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        m = new TreeMap<>();
        for(int i = 0; i < people.length; i++) {
            m.put(people[i], m.getOrDefault(people[i], 0) + 1);
        }
        
        while(!m.isEmpty()) {
            answer++;
            int weight = limit;
            // 랜덤선택도 ok
            int cur = m.lastKey(); 
            weight -= cur;
            
            if (m.get(cur) == 1) m.remove(cur);
            else m.put(cur, m.get(cur) - 1);
            
            Integer nx = m.floorKey(weight);
            if(nx != null) {
                if (m.get(nx) == 1) m.remove(nx);
                else m.put(nx, m.get(nx) - 1);        
            }
        }
        
        return answer;
    }
}