import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int[][] arr, tmp;
	static List<cctv> cctvs;
	static int[] dir;

	static int res;

	static final int[] dx = { 0, 1, 0, -1 };
	static final int[] dy = { 1, 0, -1, 0 };

	// 0 : 빈칸, 6 : 벽, 1~5 : CCTV
	// CCTV는 최대 8개

	// 1번 : 우
	// 2번 : 좌우 or 상하
	// 3번 : 좌상, 우상, 좌하, 우하
	// 4번 : 좌 뺴고, 우 빼고, 상 빼고, 우 빼고
	// 5번 : 상하좌우

	// 벽을 만나기 전까지 모두 볼 수 있다.
	// 회전 가능

	static class cctv {
		int x, y, type;

		public cctv(int x, int y, int type) {
			super();
			this.x = x;
			this.y = y;
			this.type = type;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		
		arr = new int[N][M];
		tmp = new int[N][M];
		
		cctvs = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
				if (arr[i][j] >= 1 && arr[i][j] <= 5) {
					cctvs.add(new cctv(i, j, arr[i][j]));
				}
			}
		}

		dir = new int[cctvs.size()];

		res = Integer.MAX_VALUE;

		permutation(0);
		
		sb.append(res);
		
		System.out.println(sb);
	}

	private static void permutation(int cnt) {
		// 기저
		if (cnt == cctvs.size()) {
			
			// 백트래킹 x, 그냥 값 복사해서 사용하고 버리기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmp[i][j] = arr[i][j];
				}
			}

			// cctv 순회하면서 시뮬레이션
			for (int idx = 0; idx < cctvs.size(); idx++) {
				cctv now = cctvs.get(idx);

				switch (now.type) {
				// 자기 방향만
				case 1:
					dfs(now.x, now.y, dir[idx]);
					break;
				// 내 방향, 180도
				case 2:
					dfs(now.x, now.y, dir[idx]);
					dfs(now.x, now.y, dir[idx] + 2);
					break;
				// 내 방향, 90도
				case 3:
					dfs(now.x, now.y, dir[idx]);
					dfs(now.x, now.y, dir[idx] + 3);
					break;
				// 내 방향, 90도 180도
				case 4:
					dfs(now.x, now.y, dir[idx]);
					dfs(now.x, now.y, dir[idx] + 3);
					dfs(now.x, now.y, dir[idx] + 2);
					break;
				// 4방향 탐색
				case 5:
					dfs(now.x, now.y, dir[idx]);
					dfs(now.x, now.y, dir[idx] + 1);
					dfs(now.x, now.y, dir[idx] + 2);
					dfs(now.x, now.y, dir[idx] + 3);
					break;
				}
			}

			// 사각지대 크기 구하기
			int blank = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (tmp[i][j] == 0)
						blank++;
				}
			}

			// 결과값 수정
			if (blank < res)
				res = blank;

			return;
		}

		// 유도
		for (int i = 0; i < 4; i++) {
			dir[cnt] = i;
			permutation(cnt + 1);
		}
	}

	// 감시영역 칠하기
	private static void dfs(int x, int y, int d) {
		d = d % 4;
		
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		// 경계 체크
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) return;
		
		// 빈칸일 경우
		if(tmp[nx][ny] == 0) {
			tmp[nx][ny] = 9;
			dfs(nx,ny,d);
		}
		// CCTV이거나 이미 감시하고 있는 영역일 경우
		else if((tmp[nx][ny] >= 1 && tmp[nx][ny] <= 5) || tmp[nx][ny] == 9) {
			dfs(nx,ny,d);
		}
	}
}