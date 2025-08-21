import java.util.*;

class Solution {
    
    int[] stone;
    
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;

        stone = new int[rocks.length + 2];
        for(int i = 0; i < rocks.length; i++) {
            stone[i] = rocks[i];
        }
        stone[rocks.length] = 0;
        stone[rocks.length + 1] = distance;
        
        Arrays.sort(stone);
        
        int left = 1;
        int right = distance + 1;
        
        while(left < right) {
            int mid = (left + right) / 2;
            
            if(simul(mid, n)) {
                left = mid + 1;
                answer = mid;
            }
            else {
                right = mid;
            }
        }
        
        return answer;
    }
    
    // 최소값 k 가능? / n개까지 제거 가능
    boolean simul(int k, int n) {
        int cur = 0;
        for(int i = 1; i < stone.length; i++) {
            cur += stone[i] - stone[i - 1];
            
            // 바위 제거
            if(cur < k) {
                if(--n < 0) return false;
            }
            else {
                cur = 0;
            }
        }
        
        return true;
    }
}