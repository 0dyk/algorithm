import java.util.*;

class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
    
        for(int y = 0; y < r2; ++y){
            // x^2 = r2^2 - y^2
            
            long r2y = (long)r2 * (long)r2 - (long)y * (long)y;
            long r1y = (long)r1 * (long)r1 - (long)y * (long)y;
            
            // 정수일 경우 포함
            answer += (long)Math.sqrt(r2y);
            
            // 정수일 경우 비포함
            if(y < r1){
                long tmp = (long)Math.sqrt(r1y);
                
                // 정수일 경우
                if((long)tmp * (long)tmp == r1y){
                    answer -= (tmp - 1);
                }
                // 정수 아님
                else{
                    answer -= tmp;
                }
            }
        }
        
        answer *= 4;
        
        return answer;
    }
}