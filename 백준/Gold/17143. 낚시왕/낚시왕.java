import java.io.BufferedReader;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.List;


public class Main {
    static class Shark{
        int y,x,speed,dir, big;
        Shark(int _y, int _x, int _speed, int _dir, int _big){
            y = _y;
            x = _x;
            speed = _speed;
            dir = _dir;
            big = _big;
        }
        void disappear() {
            y = -1;
            x = -1;
            speed = -1;
            dir = -1;
            big = -1;
        }
        void setShark(int _y, int _x, int _dir){
            y = _y;
            x = _x;
            dir = _dir;
        }
    }
    
    static int sero, garo, num;
    static int[][] board;
    static Shark[] sea;
    static int[] dy = {-1,1,0,0};
    static int[] dx = {0,0,1,-1};
    
    static int getShark(int x) {
        int i,id;
        for(i=1; i<=sero;++i) {
            if(board[i][x]!=0) {
                id = board[i][x];
                board[i][x]=0;
                //System.out.println(id+" 먹음");
                return id;
            }
        }
        return -1;
    }
    
    static void moveShark() {
        List<Integer> pan[][] = new ArrayList[sero+1][garo+1];
        int i,k;
        for(i=1; i<=sero; ++i) {
            for(k=1; k<=garo; ++k) {
                pan[i][k] = new ArrayList<>();
            }
        }
        int y,x,speed,dir, big;
        for(i=1; i<=num; ++i) {
            //System.out.println("hihi");
            if(sea[i].y==-1) continue;
            y = sea[i].y; x = sea[i].x; speed = sea[i].speed; dir = sea[i].dir; big = sea[i].big;
            y = y+(speed*dy[dir]);
            x = x+(speed*dx[dir]);
            
            while(!(y>=1&&y<=sero&&x>=1&&x<=garo)) {
                //System.out.println(y+" "+x);
                if(y<1) {    //안봐도 dir이 0이었음(위쪽)
                    y = 2-y;
                    dir = 1;
                }
                else if(y>sero){    //안봐도 dir이 1이었음(아래쪽)
                    y = sero-(y-sero);
                    dir = 0;
                }
                else if(x>garo) {    //안봐도 dir이 2이었음(오른쪽)
                    x = garo-(x-garo);
                    dir = 3;
                }
                else {    //안봐도 dir이 3이었음(왼쪽)
                    x = 2-x;
                    dir = 2;
                }
            }
            //System.out.println(i+" : "+"hihi "+y+" "+x);
            sea[i].setShark(y, x, dir);
            pan[y][x].add(i);
        }
        int maxSize, king=0, id;
        /*
        System.out.println();
        
        for(i=1; i<=sero; ++i) {
        	for(k=1; k<=garo; ++k) {
        		for(int t=0; t<pan[i][k].size();++t) {
        			System.out.print(i+","+k+" : "+pan[i][k].get(t)+"  /  ");
        			
        		}
        		System.out.println();
        	}
        	
        	
        }
        System.out.println("---------------------------");
        */
        for(i=1; i<=sero; ++i) {
            for(k=1; k<=garo; ++k) {
            	maxSize = -1;
                if(pan[i][k].size()==0) {
                    board[i][k]=0;
                }
                else if(pan[i][k].size()==1) {
                    board[i][k] = pan[i][k].get(0);
                }
                else {
                    for(int t=0; t<pan[i][k].size(); ++t) {
                        id = pan[i][k].get(t);
                        //System.out.print(id+" 사이즈 : "+sea[id].big+"    ");
                        if(sea[id].big>maxSize) {
                            maxSize = sea[id].big;
                            king = id;
                        }
                    }
                    for(int t=0; t<pan[i][k].size(); ++t) {
                        id = pan[i][k].get(t);
                        if(id!=king) {
                            sea[id].disappear();
                        }
                    }
                    board[i][k] = king;
                }
            }
        }
    }
    
    static int solve() {
        int i, j,k;
        int myshark, dap=0;
        /*
        for(int i=1;i<=sero; ++i) {
            for(k=1; k<=garo; ++k) {
                System.out.print(board[i][k]+" ");
            }
            System.out.println();
        }
        */
        for(k=1; k<=garo; ++k) {
            /*
            System.out.println();
            for(i=1; i<=num; ++i) {
                if(sea[i].y!=-1) {
                    System.out.println(i+" : "+sea[i].y+","+sea[i].x+" "+sea[i].dir);
                }
            }
            for(i=1; i<=sero; ++i) {
                for(j=1; j<=garo; ++j) {
                    System.out.print(board[i][j]+" ");
                }
                System.out.println();
            }
            */
            myshark = getShark(k);
            //System.out.println(myshark);
            if(myshark!=-1) {
                //System.out.println(myshark+" 먹음");
                dap+=sea[myshark].big;
                sea[myshark].disappear();
                
            }
            moveShark();
        }
        /*
        System.out.println();
        for(i=1; i<=num; ++i) {
            if(sea[i].y!=-1) {
                System.out.println(i+" : "+sea[i].y+","+sea[i].x+" "+sea[i].dir);
            }
        }
        for(i=1; i<=sero; ++i) {
            for(j=1; j<=garo; ++j) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
        */
        return dap;
    }
    
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sero = Integer.parseInt(st.nextToken());
        garo = Integer.parseInt(st.nextToken());
        num = Integer.parseInt(st.nextToken());
        int a,b,c,d,e;
        sea = new Shark[num+1];
        board = new int[sero+1][garo+1];
        for(int i=1; i<=num; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            sea[i] = new Shark(a,b,c,d-1,e);
            board[a][b] = i;
        }
        System.out.print(solve());
    }
}