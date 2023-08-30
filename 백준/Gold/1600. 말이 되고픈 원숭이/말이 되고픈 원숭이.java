import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	// 그냥 이동
	static final int[] dx = {0,0,1,-1};
	static final int[] dy = {1,-1,0,0};
	
	// 말 이동
	static final int[] dhx = {-1,-2,-2,-1,1,2,2,1};
	static final int[] dhy = {-2,-1,1,2,2,1,-1,-2};
	
	static int [][][] visited;
	static int[][] arr;

	static int K, H, W;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		K = Integer.parseInt(br.readLine());
		
		String[] str  = br.readLine().split(" ");
		
		W = Integer.parseInt(str[0]);
		H = Integer.parseInt(str[1]);
		
		arr = new int[H][W];
		visited = new int[H][W][K + 1];
		
		for(int i = 0; i < H; i++) {
			str = br.readLine().split(" ");
			for(int j = 0; j < W; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
				if(arr[i][j] == 1) arr[i][j] = -1;
			}
		}
		
		// solve
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {0, 0, 0, 0});
		visited[0][0][0] = 0;
		
		// x, y, k, dist
		
		int res = -1;
		
		while(!q.isEmpty()) {
			int[] now = q.poll();

			if(now[0] == H - 1 && now[1] == W - 1) {
				res = now[3];
				break;
			}
			
			for(int i = 0; i < 4; i++) {
				int nx = now[0] + dx[i];
				int ny= now[1] + dy[i];
				
				if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if(arr[nx][ny] == -1 || visited[nx][ny][now[2]] != 0) continue;
				
				visited[nx][ny][now[2]] = now[3] + 1;
				q.offer(new int[] {nx, ny, now[2], now[3] + 1});
			}
			
			if(now[2] < K) {
				for(int i = 0; i < 8; i++) {
					int nx = now[0] + dhx[i];
					int ny= now[1] + dhy[i];
					
					if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
					if(arr[nx][ny] == -1 || visited[nx][ny][now[2] + 1] != 0) continue;
					
					visited[nx][ny][now[2] + 1] = now[3] + 1;
					q.offer(new int[] {nx, ny, now[2] + 1, now[3] + 1});	
				}				
			}

		}
		
		System.out.println(res);
	}
}