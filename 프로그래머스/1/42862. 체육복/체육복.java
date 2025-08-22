import java.util.*;

class Solution {
    int[] remain;
    
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        remain = new int[n + 1];
        for (int k : reserve) {
            remain[k] = 2;
        }
        
        Arrays.sort(lost);
        
        answer = n;
        
        for(int k : lost) {
            if(remain[k] == 2) {
                remain[k] = 1;
            }
        }

        for(int k : lost) {
            if(remain[k] == 1) {
                continue;
            }
            if(k != 1 && remain[k - 1] == 2) {
                remain[k - 1] = 1;
            }
            else if(k != n && remain[k + 1] == 2) {     
                remain[k + 1] = 1;
            }
            else {
                 answer--;   
            }
        }
        
        
        return answer;
    }
}