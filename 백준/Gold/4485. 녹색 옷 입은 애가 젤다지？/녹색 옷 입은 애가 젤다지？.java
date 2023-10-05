import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
	static StringBuilder sb = new StringBuilder();
	
	static int N;
	static int[][] arr;
	static int[][] dist;

	static final int[] dx = {0,0,1,-1};
	static final int[] dy = {1,-1,0,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int tc = 1;
		
		N = Integer.parseInt(br.readLine());
		while(N != 0) {
			arr = new int[N][N];
			dist = new int[N][N];
			
			String[] str;
			for(int i = 0; i < N;i++) {
				str = br.readLine().split(" ");
				for(int j = 0; j< N; j++) {
					arr[i][j] = Integer.parseInt(str[j]);
					dist[i][j] = Integer.MAX_VALUE;
				}
			}
			
			int res = dijkstra();
			
			sb.append("Problem ").append(tc++).append(": ").append(res).append("\n");
			
			N = Integer.parseInt(br.readLine());
		}
		
		System.out.println(sb);
	}

	private static int dijkstra() {			
		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {return o1[2] - o2[2];});
		pq.offer(new int[] {0,0,arr[0][0]});
		dist[0][0] = arr[0][0];
		
		while(!pq.isEmpty()) {
			int cur[] = pq.poll();
			
			for(int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];
				
				// 경계 체크
				if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				
				// 갱신 체크
				if(dist[nx][ny] > dist[cur[0]][cur[1]] + arr[nx][ny]) {
					dist[nx][ny] = dist[cur[0]][cur[1]] + arr[nx][ny];
					pq.offer(new int[] {nx,ny, dist[nx][ny]});
				}
			}
		}
		
		return dist[N-1][N-1];
	}
	
}