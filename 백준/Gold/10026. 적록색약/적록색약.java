import java.io.*;

public class Main {
	static int len;
	static char[][] board;
	static boolean[][] visit;
	static int[] dy = {1,0,-1,0};
	static int[] dx = {0,1,0,-1};
	public static void dfs(int y, int x, char c) {
		visit[y][x] = true;
		int i,ny, nx;
		for(i=0; i<4; ++i) {
			ny = y+dy[i];
			nx = x+dx[i];
			if(ny>=1&&ny<=len&&nx>=1&&nx<=len) {
				if(!visit[ny][nx]&&board[ny][nx]==c) {
					dfs(ny, nx, c);
				}
			}
		}
	}
	
	public static void solve() {
	
		int i,k, count1=0, count2=0;
		visit = new boolean[len+1][len+1];
		for(i=1; i<=len; ++i) {
			for(k=1; k<=len; ++k) {
				if(!visit[i][k]) {
					count1++;
					dfs(i,k,board[i][k]);
				}
			}
		}
		
		for(i=1; i<=len; ++i) {
			for(k=1; k<=len; ++k) {
				if(board[i][k]=='R') {
					board[i][k]='G';
				}
			}
		}
		
		visit = new boolean[len+1][len+1];
		for(i=1; i<=len; ++i) {
			for(k=1; k<=len; ++k) {
				if(!visit[i][k]) {
					count2++;
					dfs(i,k,board[i][k]);
				}
			}
		}
		System.out.print(count1+" "+count2);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		len = Integer.parseInt(br.readLine());
		int i,k;
		board = new char[len+1][len+1];
		
		for(i=1; i<=len; ++i) {
			String newLine = br.readLine();
			for(k=1; k<=len; ++k) {
				board[i][k] = newLine.charAt(k-1);
			}
		}
		solve();
		
	}
}