import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Main {

	static int N, M, res;
	static ArrayList<Integer>[] adj;
	static boolean visited[];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);

		adj = new ArrayList[N];
		visited = new boolean[N];
		
		for(int i = 0; i < N; i++) {
			adj[i] = new ArrayList();
		}
		
		for(int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int a = Integer.parseInt(str[0]);
			int b = Integer.parseInt(str[1]);
			adj[a].add(b);
			adj[b].add(a);
		}
		
		res = 0;
		for(int i = 0; i < N; i++) {
			visited[i] = true;
			if(res == 0) dfs(i, 1);
			visited[i] = false;
		}
		
		System.out.println(res);
	}
	
	private static void dfs(int idx, int cnt) {
		if(cnt == 5) {
			res = 1;
			return;
		}

		for(Integer next : adj[idx]) {
			if(visited[next]) continue;
			visited[next] = true;
			dfs(next, cnt+1);
			visited[next] = false;
		}
		
	}	
}