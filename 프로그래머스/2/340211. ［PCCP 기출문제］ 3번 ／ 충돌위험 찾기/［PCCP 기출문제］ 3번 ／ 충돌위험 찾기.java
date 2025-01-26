class Solution {
    
    public class Robot {

        int x;
        int y;
        
        int n_idx;
        boolean leave;
        
        public Robot(int x, int y) {
            
            this.x = x;
            this.y = y;
            this.n_idx = 1;
            this.leave = false;
        }
    }
    
    int collision (int[][] center) {
        
        int res = 0;
        
        for(int r = 0; r < 101; ++r){
            
            for(int c = 0; c < 101; ++c){
                
                if(center[r][c] > 1) res++;
            }
        }
        
        return res;
    }
    
    void robot_move(Robot robot, int[] point){
        
        // robot -> point 이동
        if(robot.x != point[0]) {
            
            if(robot.x < point[0]) robot.x++;
            else robot.x--;
        }
        else {
            
            if(robot.y < point[1]) robot.y++;
            else robot.y--;
        }
    }
    
    public int solution(int[][] points, int[][] routes) {
        
        int answer = 0;
        
        // 2차원 좌표 n개
        // m개의 좌표로 구성된 운송경로
        // x대 로봇, 0초 동시 출발, 좌표 1만큼 이동 가능
        // 최단 경로 이동, r 먼저 c 다음
        // 2대 이상 모이면 충돌 가능성 횟수 구하기
        
        int m = routes[0].length;
        Robot[] robots = new Robot[routes.length];
        
        int[][] center = new int[101][101];
        
        for(int i = 0; i < robots.length; ++i) {
            
            robots[i] = new Robot(points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]);
            center[robots[i].x][robots[i].y]++;
        }
        
        int remain_robot = robots.length;
        answer += collision(center);
        
        while(remain_robot > 0) {
            
            for(int i = 0; i < robots.length; ++i){                
                
                if(robots[i].leave) continue;
                
                int[] cur = points[routes[i][robots[i].n_idx] - 1];
                
                center[robots[i].x][robots[i].y]--;
                robot_move(robots[i], cur);
                center[robots[i].x][robots[i].y]++;
            }
            
            answer += collision(center);
            
            for(int i = 0; i < robots.length; ++i) {
                
                if(robots[i].leave) continue;
                
                int[] cur = points[routes[i][robots[i].n_idx] - 1];
                
                if(robots[i].x == cur[0] && robots[i].y == cur[1]) {
                    
                    if(++robots[i].n_idx == m) {
                        
                        robots[i].leave = true;
                        remain_robot--;
                        center[robots[i].x][robots[i].y]--;
                    }
                }
            }
        }
        
        return answer;
    }
}