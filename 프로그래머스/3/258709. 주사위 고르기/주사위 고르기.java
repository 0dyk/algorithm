import java.util.*;

class Solution {
    
    
    static int N;
    static boolean[] isADice;
    
    static List<Integer> ADice = new ArrayList<>();
    static List<Integer> BDice = new ArrayList<>();
    
    static int[][] _dice;
    
    static int[] answer = {};
    static int maxWin = 0;
    
    static int[] AValue = new int[501];
    static int[] BValue = new int[501];
    
    void DFS(int idx, int AV, int BV) {
        if(idx == N / 2) {
            AValue[AV]++;
            BValue[BV]++;
            return;
        }
        
        for(int i = 0; i < 6; ++i) {
            DFS(idx + 1, AV + _dice[ADice.get(idx)][i], BV + _dice[BDice.get(idx)][i]);
        }
    }
    
    void fight_simulation() {
        int win = 0;
        
        for(int i = 0; i < 501; ++i) {
            AValue[i] = BValue[i] = 0;
        }
        
        ADice.clear();
        BDice.clear();
        for(int i = 0; i < isADice.length; ++i) {
            if(isADice[i]) ADice.add(i);
            else BDice.add(i);
        }
        
        DFS(0, 0, 0);
        
        // 흠.. 누적합할까?
        for(int i = 1; i < 501; ++i) {
            BValue[i] += BValue[i-1];
        }
        
        // BVlaue[i] -> i와 같거나 작은 값들의 개수
        
        // 
        int tmp = 0;
        for(int i = 1; i < 501; ++i) {
            tmp += AValue[i] * BValue[i - 1];
        }
        
        if(tmp > maxWin) {
            maxWin = tmp;
            answer = new int[N / 2];
            for(int i = 0, idx = 0; i < isADice.length; ++i) {
                if(isADice[i]) answer[idx++] = i + 1;
            }
        }
    }
    
    // 주사위 선택
    void combi(int idx, int count) {
        // 절반 뽑음
        if(count == N / 2) {
            fight_simulation();
            return;
        }
        
        // idx 초과
        if(idx >= N) return;
        
        // 뽑기
        isADice[idx] = true;
        combi(idx + 1, count + 1);
        
        // 안뽑기
        isADice[idx] = false;
        combi(idx + 1, count);
    }
    
    public int[] solution(int[][] dice) {
        _dice = dice;
        // 주사위 뽑기 10C5 => 252
        
        N = dice.length;
        isADice = new boolean[dice.length];
        combi(0, 0);
        
        return answer;
    }
}