class Solution {
    
    static int[][] dxdy = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        String answer = "";
        
        int tmp = Math.abs(x - r) + Math.abs(y - c);
        if(tmp > k || tmp % 2 != k % 2) {
            answer = "impossible";
        }
        else {
            int move = 0;
            while(x != r || y != c || move != k) {
                move++;
                
                // l 우선
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dxdy[i][0];
                    int ny = y + dxdy[i][1];

                    if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                    
                    int tmp_dist = Math.abs(nx - r) + Math.abs(ny - c);
                    
                    if(k - move >= tmp_dist) {
                        x = nx;
                        y = ny;
                        
                        if(i == 0) answer += "d";
                        else if(i == 1) answer += "l";
                        else if(i == 2) answer += "r";
                        else answer += "u";
                        
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
}