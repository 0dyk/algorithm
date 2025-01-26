class Solution {
    
    int string_to_int(String str) {
        
        int res = 0;
        res += (str.charAt(0) - '0') * 600;
        res += (str.charAt(1) - '0') * 60;
        res += (str.charAt(3) - '0') * 10;
        res += (str.charAt(4) - '0');
        
        return res;
    }
    
    String int_to_string(int k) {

        String res = "";
        
        int m = k / 60;
        int s = k % 60;
        
        return String.format("%02d:%02d", m, s);
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        
        String answer = "";
        
        // prev : 10초 전 이동, next : 10초 후 이동, 오프닝 건너뛰기

        int video = string_to_int(video_len);
        int p = string_to_int(pos);
        int os = string_to_int(op_start);
        int oe = string_to_int(op_end);
        
        
        if(p >= os && p <= oe) p = oe;
        
        for(int i = 0; i < commands.length; ++i){
            
            if(commands[i].charAt(0) == 'p') {
                
                p -= 10;
                if(p < 0) p = 0;
            }
            else if(commands[i].charAt(0) == 'n'){
                
                p += 10;
                if(p > video) p = video; 
            }
            
            if(p >= os && p <= oe) p = oe;
        }
        
        answer = int_to_string(p);
        
        return answer;
    }
}