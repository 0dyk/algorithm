
class Solution {
    
    long puzzle_simul(long level, int[] diffs, int[] times) {
        
        long time = 0;
        
        for(int i = 0; i < diffs.length; ++i){
            
            if(level >= diffs[i]){
                
                time += times[i];
            }
            else{
                time += (diffs[i] - level) * (times[i] + (i == 0 ? 0 : times[i-1])) + times[i];
            }
        }
        
        return time;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {

        int answer = 0;

        // 숙련도 이분탐색
        long left = 1;
        long right = 100000;

        while(left <= right){

            long mid = (left + right) / 2;

            long time = puzzle_simul(mid, diffs, times);

            if(time <= limit){
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }
        
        answer = (int)left;
        
        return answer;
    }
}