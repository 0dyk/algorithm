import java.util.*;

class Solution {
    public int solution(int[] cards) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        boolean[] visited =  new boolean[cards.length + 1];
        
        for(int i = 0; i < cards.length; ++i){
            
            if(visited[i + 1]) continue;
            
            visited[i + 1] = true;
            int idx = i + 1;
            int groupSize = 1;
            
            while(true) {
                int next = cards[idx - 1];
                
                if(visited[next]) break;
                
                visited[next] = true;
                idx = next;
                groupSize++;
            }
            
            System.out.println(i + " / " + groupSize);

            list.add(groupSize);
        }
        
        int answer = 0;
        if(list.size() == 1) answer = 0;
        else {
            Collections.sort(list);
            answer = list.get(list.size() - 1) * list.get(list.size() - 2);
        }
        
        return answer;
    }
}