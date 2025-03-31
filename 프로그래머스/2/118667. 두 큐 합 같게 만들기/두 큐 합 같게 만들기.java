import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        
        long sum1 = 0, sum2 = 0;
        
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        
        for(int i = 0; i < queue1.length; ++i) {
            sum1 += queue1[i];
            sum2 += queue2[i];
            
            list1.add(queue1[i]);
            list2.add(queue2[i]);
        }
        
        int sz1 = queue1.length, sz2 = queue2.length;
        int idx1 = 0, idx2 = 0;
        
        while(sum1 != sum2) {
            if(idx1 >= sz1 && idx2 >= sz2) {
                answer = -1;
                break;
            }
            
            if(sum1 > sum2) {
                sum1 -= list1.get(idx1);
                sum2 += list1.get(idx1);
                
                list2.add(list1.get(idx1++));
            }
            else {
                sum1 += list2.get(idx2);
                sum2 -= list2.get(idx2);
                
                list1.add(list2.get(idx2++));
            }
            
            ++answer;
        }
        
        
        return answer;
    }
}