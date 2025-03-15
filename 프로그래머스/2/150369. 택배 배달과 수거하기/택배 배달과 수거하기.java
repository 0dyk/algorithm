import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        
        for(int i = n - 1; i >= 0; --i) {
            // 안와도 되는 경우
            if(deliveries[i] == 0 && pickups[i] == 0) continue;
            
            // k번 왔다갔다 해야함.
            int k = Math.max(deliveries[i], pickups[i]) / cap;
            if (Math.max(deliveries[i], pickups[i]) % cap != 0) k++;
            
            answer += (k * 2) * (i + 1);

            int del_tmp = k * cap - deliveries[i];
            int idx = i - 1;
            while(idx >= 0 && del_tmp > 0) {
                if(deliveries[idx] - del_tmp >= 0 ) {
                    deliveries[idx] -= del_tmp;
                    break;
                }
                else {
                    del_tmp -= deliveries[idx];
                    deliveries[idx] = 0;
                    idx--;
                }
            }
            
            int pic_tmp = k * cap - pickups[i];
            idx = i - 1;
            while(idx >= 0 && pic_tmp > 0) {
                if(pickups[idx] - pic_tmp >= 0 ) {
                    pickups[idx] -= pic_tmp;
                    break;
                }
                else {
                    pic_tmp -= pickups[idx];
                    pickups[idx] = 0;
                    idx--;
                }
            }
            
            deliveries[i] = 0;
            pickups[i] = 0;
        }

        return answer;
    }
}