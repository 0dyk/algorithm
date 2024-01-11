import java.util.*;

class Solution {
    
    // 과제 : 이름, 시작 시간, 길이
    public class gwaje implements Comparable<gwaje> {
        String name;
        int start;
        int len;
        
        public gwaje (String name, int start, int len){
            this.name = name;
            this.start = start;
            this.len = len;
        }
        
        public int compareTo(gwaje other){
            return Integer.compare(this.start, other.start);
        }
    }
    
    // String -> int
    public int calTime(String mmss){
        int res = mmss.charAt(0) * 600
                + mmss.charAt(1) * 60
                + mmss.charAt(3) * 10
                + mmss.charAt(4);
        return res;
    }
    
    public static gwaje[] arr;
    
    // Solution
    public String[] solution(String[][] plans) {
        int idx = 0;
        String[] answer = new String[plans.length];

        arr = new gwaje[plans.length];

        for(int i = 0; i < plans.length; ++i) {
            arr[i] = (new gwaje(plans[i][0],
                    calTime(plans[i][1]),
                    Integer.parseInt(plans[i][2])));
        }

        Arrays.sort(arr);

        // 시작 시간이 늦은 순으로 체크 -> 대기 큐
        PriorityQueue<gwaje> pq = new PriorityQueue<>(Collections.reverseOrder());

        // 대기 시간이 빠른 것 부터 처리
        // gwaje pre = null;
        for(int i = 0; i < arr.length; ++i){

            // 처리학 작업이 없으면
            if(pq.isEmpty()){
                pq.offer(arr[i]);
                continue;
            }

            // 새로운 과제 시작까지 남은 시간
            int dif = arr[i].start - pq.peek().start;

            // 처리 가능?
            int tmp = dif - pq.peek().len;

            // 딱 처리 가능!
            if(tmp == 0){
                answer[idx++] = pq.poll().name;
                pq.offer(arr[i]);
            }
            // 처리하고 시간이 남아!
            else if(tmp > 0){
                answer[idx++] = pq.poll().name;

                // 더 처리할 작업이 있는가?
                while(tmp > 0 && !pq.isEmpty()){
                    // 시간 부족으로 처리 못함
                    if(pq.peek().len > tmp){
                        pq.peek().len -= tmp;
                        break;
                    }
                    // 처리하고 다음 거 확인 해보자
                    else{
                        answer[idx++] = pq.peek().name;
                        tmp -= pq.poll().len;
                    }
                }

                pq.offer(arr[i]);
            }
            // 시간 부족인 경우
            else {
                pq.peek().len = -tmp;
                pq.offer(arr[i]);
            }
        }

        while(!pq.isEmpty()){
            answer[idx++] = pq.poll().name;
        }

        return answer;
    }
}