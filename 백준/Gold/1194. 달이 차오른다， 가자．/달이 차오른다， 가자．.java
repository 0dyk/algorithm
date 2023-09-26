import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

public class Main {

	
	static int N, M;
	static char[][] arr;
	static int[][][] dist;
	
	static int sx, sy;
	static int res;
	
	static final int[] dx = {0,0,1,-1};
	static final int[] dy = {1,-1,0,0};
	
	/*
	 * . : 빈칸
	 * # : 벽
	 * 소문자 : 열쇠
	 * 대문자 : 문
	 * 0 : 현재위치
	 * 1 : 도착위치
	 * 
	 */
	
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		
		arr = new char[N][M];
//		visited = new boolean[N][M][6];
		dist = new int[N][M][65];
		
		res = -1;
		
		for(int i = 0; i< N; i++) {
			String s = br.readLine();
			for(int j = 0; j < M; j++) {
				arr[i][j] = s.charAt(j);
				
				// 시작 위치
				if(arr[i][j] == '0') {
					sx = i; sy = j;
				}
			}
		}
		
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				for(int k = 0; k < 65; k++) {
					dist[i][j][k] = Integer.MAX_VALUE;
				}
			}
		}
		
		dist[sx][sy][0] = 0;
		
		dfs(sx, sy, 0);
		
		System.out.println(res);
	}

	private static void dfs(int x, int y, int k) {
		// 기저조건
		if(arr[x][y] == '1') {
			if(res == -1 || dist[x][y][k] < res) {
				res = dist[x][y][k];
				return;
			}
		}
		
		for(int i = 0; i <4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			// 경계, 벽 체크
			if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == '#') continue;
			
			// 빈 공간
			else if(arr[nx][ny] == '.' || arr[nx][ny] == '0' || arr[nx][ny] == '1') {
				// 갱신이 되는 경우만
				if(dist[nx][ny][k] > dist[x][y][k] + 1) {
					dist[nx][ny][k] = dist[x][y][k] + 1;
					dfs(nx, ny , k);
				}
			}
			
			// 열쇠인 경우
			else if(arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
				// a 인 경우 0칸 밀고 합비트
				int nk = k | (1 << (arr[nx][ny] - 'a'));
				
				if(dist[nx][ny][nk] > dist[x][y][k] + 1) {
					dist[nx][ny][nk] = dist[x][y][k] + 1;
					dfs(nx, ny , nk);
				}
			}
			
			// 문인 경우
			else if(arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
				int door =  1 << (arr[nx][ny] - 'A');
				// 키가 존재하는 경우
				if((door & k) != 0 && dist[nx][ny][k] > dist[x][y][k] + 1) {
					dist[nx][ny][k] = dist[x][y][k] + 1;
					dfs(nx, ny, k);
				}
			}
		}
	}
}