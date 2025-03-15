import java.util.*;

class Solution {
    
    public boolean expire_day(String today, String day, int term) {
        String[] tod = today.split("\\.");
        String[] d = day.split("\\.");
        
        int ty = Integer.parseInt(tod[0]);
        int tm = Integer.parseInt(tod[1]);
        int td = Integer.parseInt(tod[2]);
        int ny = Integer.parseInt(d[0]);
        int nm = Integer.parseInt(d[1]);
        int nd = Integer.parseInt(d[2]);
        
        nm += term;
        while(nm > 12) {
            nm -= 12;
            ny++;
        }
        
        if(nd == 1) {
            if((nm <= 7 && nm % 2 == 1) || (nm >= 8 && nm % 2 == 0)) nd = 31;
            else nd = 30;
            
            if(--nm == 0) {
                nm = 12;
                ny--;
            }
        } 
        else {
            nd--;
        }
        
        // today가 더 크면 true == 파괴
        if(ty > ny) return true;
        else if(ty == ny) {
            if(tm > nm) return true;
            else if(tm == nm) {
                if(td > nd) return true;
            }
        }
        
        return false;
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] answer = {};
        
        List<Integer> res = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        
        for(String str : terms) {
            String[] s = str.split(" ");
            m.put(s[0], Integer.parseInt(s[1]));
        }
        
        for(int i = 0; i < privacies.length; ++i) {
            String[] s = privacies[i].split(" ");
            
            if(expire_day(today, s[0], m.get(s[1]))) {
                res.add(i + 1);
            }
        }
        
        answer = res.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
}