import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	static final int[] dx = {0, 0, 1, -1};
	static final int[] dy = {1, -1, 0, 0};
	
	static int R, C;
	static char[][] arr;
	
	// 물이 퍼지는 시간
	static int[][] time;
	
	// 고슴 도치 이동 시간
	static int[][] gosm;

	// 방문체크
	static boolean[][] visited;
	
	// 고슴 도치 위치
	static int sx, sy;
	
	// 비버굴 위치
	static int ex, ey;
	
	/*
	 * . : 빈 공간
	 * * : 물
	 * X : 돌
	 * D : 비버 굴
	 * S : 고슴도치
	 * 
	 */
	


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		
		R = Integer.parseInt(str[0]);
		C = Integer.parseInt(str[1]);
		
		arr = new char[R][C];
		time = new int[R][C];
		gosm =new int[R][C];
		visited = new boolean[R][C];
		
		// 물 퍼지는 시간 체크
		Queue<int[]> q = new ArrayDeque<>();

		for(int i = 0; i < R; i++) {
			String s = br.readLine();
			for(int j = 0; j < C; j++) {
				arr[i][j] = s.charAt(j);
				if(arr[i][j] == '*') q.offer(new int[] {i, j});
				else if(arr[i][j] == 'S') {sx = i; sy = j;}
				else if(arr[i][j] == 'D') {ex = i; ey = j;}
			}
		} //end::input
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			for(int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];
				
				// 경꼐 체크
				if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			
				// 빈공간, 아직 오염 안된 경우
				if(arr[nx][ny] == '.' && time[nx][ny] == 0) {
					time[nx][ny] = time[cur[0]][cur[1]] + 1;
					q.offer(new int[] {nx, ny});
				}
			}
		} //end::water
		
		q.offer(new int[] {sx, sy});
		visited[sx][sy] = true;
		
		int res = -1;
		boolean fin = true;
		while(!q.isEmpty() && fin) {
			int x = q.peek()[0];
			int y = q.peek()[1];
			q.poll();
			
			for(int i = 0; i< 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				// 경계 체크, 벽, 물 체크
				if(nx < 0 || nx >= R || ny < 0 || ny >= C || 
						arr[nx][ny] == 'X' || arr[nx][ny] == '*' || visited[nx][ny]) continue;
				
				// 도착
				if(nx == ex && ny == ey) {
					res = gosm[x][y] + 1;
					fin = false;
					break;
				}
				
				// 물이 안오는 공간이거나, 물 퍼지는 시간보다 먼저 도착하는 경우
				if(time[nx][ny] == 0 || time[nx][ny] > gosm[x][y] + 1) {
					gosm[nx][ny] = gosm[x][y] + 1;
					visited[nx][ny] = true;
					q.offer(new int[] {nx, ny});
				}				
			}
		}//end::gosm
		
		if(res == -1) {
			System.out.println("KAKTUS");
		}else {
			System.out.println(res);
		}
	}
}