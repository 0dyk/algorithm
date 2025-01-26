import java.util.*;

class Solution {
    
    void out_check(boolean[] format, int value) {
        
        for(int i = 2; i <= 9; ++i) {
            
            if(!format[i]) continue;
            
            int tmp = value;
            
            while(tmp > 0) {
                
                if(tmp % 10 >= i) format[i] = false;
                tmp /= 10;
            }
        }
    }
    
    int ten_to_k(int value, int k) {
        
        int res = 0;
        int a = 1;
        
        while(value > 0) {
            
            res += (value % 10) * a;
            a *= k;
            value /= 10;
        }

        return res;
    }
    
    int k_to_ten(int value, int k) {
        
        int res = 0;
        int a = 1;
        
        while (value > 0) {
            
            res += (value % k) * a;
            a *= 10;
            value /= k;
        }
        
        return res;
    }
    
    public String[] solution(String[] expressions) {
        
        String[] answer = {};
        
        boolean[] format = new boolean[10];
        Arrays.fill(format, true);
        
        for(int i = 0; i < expressions.length; ++i){
            
            String[] expr = expressions[i].split(" ");
            
            int first = Integer.parseInt(expr[0]);
            int second = Integer.parseInt(expr[2]);
            
            out_check(format, first);
            out_check(format, second);
            
            if(expr[4].equals("X")) continue;
            int result = Integer.parseInt(expr[4]);
            
            out_check(format, result);
            
            // 2 ~ 9진법
            for(int k = 2; k <= 9; ++k){
                
                if(!format[k]) continue;
                
                int tmp_f = ten_to_k(first, k);
                int tmp_s = ten_to_k(second, k);
                int tmp_r = ten_to_k(result, k);
                
                if(expr[1].equals("+") && tmp_f + tmp_s != tmp_r) {
                    
                    format[k] = false;
                }
                else if (expr[1].equals("-") && tmp_f - tmp_s != tmp_r) {
                    
                    format[k] = false;
                }
            }
        }
        
        List<String> tmp_ans = new ArrayList<>();
        
        for(int i = 0; i < expressions.length; ++i){
        
            String[] expr = expressions[i].split(" ");
        
            int first = Integer.parseInt(expr[0]);
            int second = Integer.parseInt(expr[2]);
            
            if(!expr[4].equals("X")) continue;
            
            boolean flag = false;
            int res = 0;
            boolean check = false;
            
            for(int k = 2; k <= 9; ++k) {
                
                if(!format[k]) continue;
                
                int tmp_f = ten_to_k(first, k);
                int tmp_s = ten_to_k(second, k);
                
                int tmp_r = 0;
                
                if(expr[1].equals("+")) {
                    
                    tmp_r = tmp_f + tmp_s;
                }
                else{
                    
                    tmp_r = tmp_f - tmp_s;
                }
                
                tmp_r = k_to_ten(tmp_r, k);
                
                if(!flag) {
                    
                    flag = true;
                    res = tmp_r;
                }
                else if(res != tmp_r) {
                    
                    System.out.println("ㅃㅃ");
                    
                    check = true;
                    break;
                }
            }
            
            if(check) tmp_ans.add(expr[0] + " " + expr[1] + " " + expr[2] + " " + expr[3] + " " + "?");
            else tmp_ans.add(expr[0] + " " + expr[1] + " " + expr[2] + " " + expr[3] + " " + Integer.toString(res));
        }

        answer = tmp_ans.toArray(new String[0]);
        
        return answer;
    }
}