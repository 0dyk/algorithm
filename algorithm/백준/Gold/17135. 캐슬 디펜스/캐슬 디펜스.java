import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N, M, D;
	static int[][] arr;
	static int[] bow;
	static boolean visited[];
	static int enemy;
	static int[][] tmp;
	static int maxEnemy;
	
	static class pos{
		int x, y;

		public pos(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		D = Integer.parseInt(str[2]);
		
		enemy = 0;
		arr = new int[N][M];
		tmp = new int[N][M];
		for(int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for(int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
				if(arr[i][j] == 1) enemy++;
			}
		}
		
		maxEnemy = 0;
		bow = new int[3];
		visited = new boolean[M];
		combination(0, 0);
		System.out.println(maxEnemy);
	}
	
	// 궁수 배치 정하기
	private static void combination(int idx, int cnt) {
		if(cnt == 3) {
			shoot();
			return;
		}
		
		for(int i = idx; i < M; i++) {
			bow[cnt] = i;
			combination(i + 1, cnt + 1);
		}
	}
	
	private static void shoot() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		
		// juk : 남은 적
		// kill 죽인 수
		int juk = enemy;
		int kill = 0;
		while(juk != 0) {
			// 사격 실시
			pos s1 = findE(bow[0]);
			pos s2 = findE(bow[1]);
			pos s3 = findE(bow[2]);
			
			if(s1.x != -1) {
				tmp[s1.x][s1.y] = 0;
				juk--; kill++;
				}
			if(s2.x != -1 && tmp[s2.x][s2.y] == 1) {
				tmp[s2.x][s2.y] = 0;
				juk--; kill++;
				}
			if(s3.x != -1 && tmp[s3.x][s3.y] == 1) {
				tmp[s3.x][s3.y] = 0;
				juk--; kill++;
				}
		
			// 적 이동,
			for(int i = N-1; i >= 0; i--) {
				for(int j = 0; j < M; j++) {
					// 적이 성을 공격
					if(i == N-1 && tmp[i][j] == 1) {
						juk--;
						tmp[i][j] = 0;
					}
					// 적 한칸 아래로 이동
					if(i != N-1 && tmp[i][j] == 1) {
						tmp[i+1][j] = 1;
						tmp[i][j] = 0;
					}
				}
			}
		}
		
		if(kill > maxEnemy) maxEnemy = kill;
	}
	
	static final int dx[] = {0,-1,0};
	static final int dy[] = {-1,0,1};
	
	private static pos findE(int col) {		
		Queue<pos> q = new ArrayDeque<>();
		q.offer(new pos(N, col));
		

		boolean check[][] = new boolean[N][M];
		
		while(!q.isEmpty()) {
			pos now = q.poll();
			
			// 거리 초과시
			if(Math.abs(N-now.x) + Math.abs(col - now.y) > D) break;
			
			// 에너미를 찾을 경우
			if(now.x != N && tmp[now.x][now.y] == 1) {
				return new pos(now.x, now.y);
			}
			
			for(int i = 0; i < 3; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				
				if(nx < 0 || nx >= N || ny < 0 || ny >= M || check[nx][ny]) continue;
				check[nx][ny] = true;
				q.offer(new pos(nx, ny));
			}
		}
		
		return new pos(-1,-1);
	}
}