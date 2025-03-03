import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {
        int answer = 0;

        int n = cards.length;

        int[] needCoin = new int[n + 1];
        for(int i = 0; i < n + 1; ++i) needCoin[i] = -1;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i = 0; i < n / 3; ++i) {
            if(needCoin[n + 1 - cards[i]] == 0) {
                needCoin[n + 1 - cards[i]] = -1;
                pq.offer(0);
            }
            else {
                needCoin[cards[i]] = 0;
            }
        }
        
        for(int i = n / 3; i <= n; i += 2) {
            answer++;
            if(i == n) {
                break;
            }
            
            needCoin[cards[i]] = 1;
            if(needCoin[n + 1 - cards[i]] != -1) {
                pq.offer(needCoin[n + 1 - cards[i]] + needCoin[cards[i]]);
            }
            
            needCoin[cards[i + 1]] = 1;
            if(needCoin[n + 1 - cards[i + 1]] != -1) {
                pq.offer(needCoin[n + 1 - cards[i + 1]] + needCoin[cards[i + 1]]);
            }
            
            if(!pq.isEmpty() && pq.peek() <= coin) {
                coin -= pq.poll();
            }else{
                break;
            }
        }
        
        return answer;
    }
}