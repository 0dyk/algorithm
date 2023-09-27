import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class Vertex{
		int y;
		int x;
		int count;
		public Vertex(int y, int x, int count) {
			super();
			this.y = y;
			this.x = x;
			this.count = count;
		}
		@Override
		public String toString() {
			return "Vertex [y=" + y + ", x=" + x + ", count=" + count + "]";
		}
		
	}
	
	// 상 하 좌 우
	static int dy[] = {-1, 1, 0, 0};
	static int dx[] = {0, 0, -1, 1};
	
	static int R, C, result=Integer.MAX_VALUE;
	static char[][] map;
	static boolean[][] visited;
	
	static Queue<int[]> flood = new ArrayDeque<>();
		
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String input[] = in.readLine().split(" ");
		R = Integer.parseInt(input[0]);
		C = Integer.parseInt(input[1]);
		map = new char[R][C];
		
		int sy = 0;
		int sx = 0;
		
		for(int i=0; i<R; i++) {
			String str = in.readLine();
			for(int j=0; j<C; j++) {
				map[i][j] = str.charAt(j);
				if(map[i][j] == 'S') {
					sy = i;
					sx = j;
				}
				if(map[i][j] == '*') {
					flood.offer(new int[]{i, j});
				}
			}
		}
		
		solve(sy, sx);
		
		// result가 초기값이라면 KAKTUS 출력
		if(result==Integer.MAX_VALUE)
			System.out.println("KAKTUS");
		else
			System.out.println(result);
			
	}
	
	static void solve(int sy, int sx) {
		Queue<Vertex> q = new ArrayDeque<>();
		visited = new boolean[R][C];
		
		q.offer(new Vertex(sy, sx, 0));
		visited[sy][sx] = true;
		
		while(!q.isEmpty()) {
			int qSize = q.size();
			for(int s=0; s<qSize; s++) {
				Vertex cur = q.poll();
				
				if(map[cur.y][cur.x] == 'D') {
					result = Math.min(result, cur.count);
					continue;
				}
				for(int d=0; d<dy.length; d++) {
					int ny = cur.y + dy[d];
					int nx = cur.x + dx[d];
					
					if(canGo(ny, nx)) {
						visited[ny][nx] = true;
						q.offer(new Vertex(ny, nx, cur.count+1));
					}
				}
			}
			// 물 범람
			qSize = flood.size();
			for(int s=0; s<qSize; s++) {
				int fy = flood.peek()[0];
				int fx = flood.poll()[1];					

				for(int d=0; d<dy.length; d++) {
					int ny = fy+dy[d];
					int nx = fx+dx[d];
					
					if(inMap(ny, nx) && map[ny][nx]!='D' && map[ny][nx]!='X' && map[ny][nx]!='*') {
						map[ny][nx] = '*';
						flood.offer(new int[] {ny, nx});
					}
				}
			}
			
		}
	}
	
	static boolean canGo(int y, int x) {
		if(inMap(y, x) && !visited[y][x] && map[y][x]!='*' && map[y][x]!='X') {
			if(map[y][x]=='D') return true;
			for(int d=0; d<dy.length; d++) {
				int ny = y+dy[d];
				int nx = x+dx[d];
				
				if(inMap(ny, nx) && map[ny][nx]=='*') return false;
			}
			
			return true;
		}
		
		return false;
	}
	static boolean inMap(int y, int x) {
		return 0<=y && y<R && 0<=x && x<C;
	}
}