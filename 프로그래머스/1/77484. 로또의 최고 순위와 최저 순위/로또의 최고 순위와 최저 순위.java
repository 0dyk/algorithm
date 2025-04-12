class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = { 1, 1 };
        
        boolean[] lotto_num = new boolean[46];
        
        for (int i = 0; i < 6; ++i) {
            lotto_num[win_nums[i]] = true;
        }
        
        for(int i = 0; i < 6; ++i) {
            if(lottos[i] == 0) {
                answer[1]++;
            }
            else if(lotto_num[lottos[i]] == true) {
                //
            } else {
                answer[0]++;
                answer[1]++;
            }
        }
        
        if(answer[0] > 6) answer[0] = 6;
        if(answer[1] > 6) answer[1] = 6;
        
        
        return answer;
    }
}