import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Main {

	static int N, M, k;
	static int[][] arr;
	static int[][] adjMatrix;
	static List<int[]> adjList;
	static int cost;
	
	static final int[] dx = {0,0,1,-1};
	static final int[] dy = {1,-1,0,0};
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		
		arr = new int[N][M];
		adjList = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for(int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
			}
		}
		
		draw();
		
		adjMatrix = new int[k+1][k+1];
		
		calDist();
		
		kruskal();
		
		System.out.println(cost);
	}
	
	
	static int[] par;
	// 연결하기
	private static void kruskal() {
		adjList.sort((a, b) -> Integer.compare(a[2], b[2]));
		
		par = new int[k + 1];
		for(int i = 2; i <= k; i++) {
			par[i] = i;
		}
		
		cost = 0;
		for(int i = 0; i < adjList.size(); i++) {
			if(find(adjList.get(i)[0]) != find(adjList.get(i)[1])) {
				cost += adjList.get(i)[2];
				union(adjList.get(i)[0], adjList.get(i)[1]);
			}
		}
		
		int x = find(2);
		for(int i = 3; i <= k; i++) {
			if(x != find(i)) cost = -1;
		}
		
	}

	private static void union(int i, int j) {
		int pa = find(i);
		int pb = find(j);
		
		if(pa != pb) par[pb] = pa;
	}

	private static int find(int i) {
		if(par[i] == i ) return i;
		else return par[i] = find(par[i]);
	}

	// 거리 구하기
	private static void calDist() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(arr[i][j] != 0) {
					// 4 방향으로 길 탐색하기
					
					for(int d = 0 ;d < 4; d++) {
						int dist = 0;
						int nx = i + dx[d], ny = j + dy[d];
						
						if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						
						while(!(nx < 0 || nx >= N || ny < 0 || ny >= M)
								&& arr[nx][ny] == 0) {
							nx += dx[d];
							ny += dy[d];
							++dist;
						}
						
						// 도착했을 때
						if(dist >= 2) {
							// 아직 길이 없었거나, 길이 줄어드는 경우 
							if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if(arr[i][j] == 0 || arr[nx][ny] == 0) continue;
							
							if(adjMatrix[arr[i][j]][arr[nx][ny]] == 0 || adjMatrix[arr[i][j]][arr[nx][ny]] > dist) {
								adjMatrix[arr[i][j]][arr[nx][ny]] = dist;
								adjMatrix[arr[nx][ny]][arr[i][j]] = dist;
							}
						}
					}
				}
			}
		}
		
		for(int i = 2; i <= k; i++) {
			for(int j = i + 1; j <= k; j++) {
				if(adjMatrix[i][j] != 0) {
					adjList.add(new int[]{i, j, adjMatrix[i][j]});
				}
			}
		}
	}//end::calDist

	// 섬 구별하기 2 ~ k번 섬, k-1개
	private static void draw() {
		k = 1;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(arr[i][j] == 1) {
					Queue<int[]> q = new ArrayDeque<>();
					q.offer(new int[] {i,j});
					arr[i][j] = ++k;
					
					while(!q.isEmpty()) {
						int[] cur = q.poll();
						
						for(int a = 0; a < 4; a++) {
							int nx = cur[0] + dx[a];
							int ny = cur[1] + dy[a];
							
							if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 1) continue;
						
							arr[nx][ny] = k;
							q.offer(new int[] {nx, ny});
						}
					}
				}
			}
		}
	}//end::draw
}