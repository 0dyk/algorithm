import java.util.*;

class Solution {
    
    static long[] adv_stamp;
    
    public String solution(String play_time, String adv_time, String[] logs) {
        String answer = "";
        
        adv_stamp = new long[360001];
        
        int p_time_second = timeToSecond(play_time); // 전체 플레이 타임
        int a_time_second = timeToSecond(adv_time); // 광고 시간
        
        for(int i = 0; i < logs.length; ++i) {
            int cur_start = timeToSecond(logs[i].substring(0, 8));
            int cur_end = timeToSecond(logs[i].substring(9, 17));

            adv_stamp[cur_start]++;
            adv_stamp[cur_end]--;
        }

        // 각 시간대별 시청자 수
        for(int i = 1; i <= p_time_second; ++i) {
            adv_stamp[i] += adv_stamp[i-1];
        }
        
        // 누적 시청자 수
        for(int i = 1; i <= p_time_second; ++i) {
            adv_stamp[i] += adv_stamp[i-1];
        }

        long  max_value = adv_stamp[a_time_second - 1];
        int start_time = 0;
        
        for(int i = 1; i + a_time_second - 1 <= p_time_second; ++i) {
            long v = adv_stamp[i + a_time_second - 1] - adv_stamp[i - 1];
            
            if(v > max_value) {
                max_value = v;
                start_time = i;
            }
        }
        
        answer = secondToTime(start_time);
        
        return answer;
    }
    
    static int timeToSecond (String time) {
        String hour = time.substring(0, 2);
        String min = time.substring(3, 5);
        String sec = time.substring(6, 8);
        
        int ret = Integer.parseInt(hour) * 3600 + Integer.parseInt(min) * 60 + Integer.parseInt(sec);

        return ret;
    }
    
    static String secondToTime (int time) {
        int hour = time / 3600;
        int min = (time % 3600) / 60;
        int sec = time % 60;
        
        String ret = String.format("%02d:%02d:%02d", hour, min, sec);
        
        return ret;
    }
}