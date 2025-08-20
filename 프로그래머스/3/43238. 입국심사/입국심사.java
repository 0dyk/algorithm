import java.util.Arrays;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        Arrays.sort(times);
        
        // 이분탐색
        long left = 1;
        long right = n * 1000000000L / times.length;
        
        while(left < right) {
            long mid = (left + right) / 2;
            
            if(checkSimul(n, times, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        answer = left;
        
        return answer;
    }
    
    // k분에 심사 가능한가?
    boolean checkSimul(int n, int[] times, long k) {
        long cnt = 0;
        for(int i = 0; i < times.length; i++) {
            cnt += k / times[i];
        }
        return cnt >= n;
    }    
}