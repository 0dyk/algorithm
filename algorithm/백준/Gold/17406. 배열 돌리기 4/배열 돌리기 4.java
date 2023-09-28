import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int N, M, K;
	static int[][] arr;
	static int r, c, s;
	static int[][] permu;
	static boolean[] visited;
	static int min;
	static int[] t;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		K = Integer.parseInt(str[2]);
		
		arr = new int[N + 1][M + 1];
		for(int i = 1; i <= N; i++) {
			str = br.readLine().split(" ");
			for(int j = 1; j <= M; j++) {
				arr[i][j] = Integer.parseInt(str[j - 1]);
			}
		}
				
		visited = new boolean[K];
		permu = new int[K][3];
		for(int i = 0; i < K; i++) {
			str = br.readLine().split(" ");
			permu[i][0] = Integer.parseInt(str[0]);
			permu[i][1] = Integer.parseInt(str[1]);
			permu[i][2] = Integer.parseInt(str[2]);
		}

		min = Integer.MAX_VALUE;
		
        t = new int[K];
		permutation(0);

		System.out.println(min);
	}
	
	
	public static void permutation(int cnt) {
		if(cnt == K) {	
			for(int i = 1; i <= N; i++) {
				int tmp = 0;
				for(int j = 1; j <= M; j++) {
					tmp += arr[i][j];
				}
				if(tmp < min) min = tmp;
			}
			return;
		}
		
		for(int i = 0; i < K; i++) {
			if(visited[i]) continue;
			visited[i] = true;
			rotate(permu[i][0] - permu[i][2], permu[i][1] - permu[i][2], permu[i][2] * 2);
			permutation(cnt + 1);
			visited[i] = false;
			rerotate(permu[i][0] - permu[i][2], permu[i][1] - permu[i][2], permu[i][2] * 2);
		}
	}
	
	// x, y : 좌상단
	public static void rotate(int x, int y, int size) {		
		while(size > 1) {
			int tmp = arr[x][y];
			for(int i = 0; i < size; i++) arr[x + i][y] = arr[x + 1 + i][y];
			for(int i = 0; i < size; i++) arr[x + size][y + i] = arr[x + size][y + 1 + i];
			for(int i = 0; i < size; i++) arr[x + size - i][y + size] = arr[x + size - 1 - i][y + size];
			for(int i = 0; i < size - 1; i++) arr[x][y + size - i] = arr[x][y + size - 1 - i];
			arr[x][y + 1] = tmp;
			
			x++; y++;
			size -= 2;
		}
	}
	
	public static void rerotate(int x, int y, int size) {		
		while(size > 1) {
			int tmp = arr[x][y];
			for(int i = 0; i < size; i++) arr[x][y + i] = arr[x][y + 1 + i];
			for(int i = 0; i < size; i++) arr[x + i][y + size] = arr[x + 1 + i][y + size];
			for(int i = 0; i < size; i++) arr[x + size][y + size - i] = arr[x + size][y + size - 1 - i];
			for(int i = 0; i < size - 1; i++) arr[x + size - i][y] = arr[x + size - 1 - i][y];
			arr[x + 1][y] = tmp;
			
			x++; y++;
			size -= 2;
		}
	}
}
