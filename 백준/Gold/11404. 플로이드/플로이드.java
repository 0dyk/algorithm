import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int N;	// 정점의 수
		N = Integer.parseInt(in.readLine());
		int M = Integer.parseInt(in.readLine());
		
		int adjMatrix[][] = new int[N][N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				adjMatrix[i][j] = Integer.MAX_VALUE;
			}
		}
		
		for(int i=0; i<M; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			
			int start = Integer.parseInt(st.nextToken()) -1;
			int end = Integer.parseInt(st.nextToken()) -1;
			int cost = Integer.parseInt(st.nextToken());
			
			if(adjMatrix[start][end] > cost)
				adjMatrix[start][end] = cost;
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(adjMatrix[i][k]!=Integer.MAX_VALUE && adjMatrix[k][j]!=Integer.MAX_VALUE
							&& adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j])
						adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(adjMatrix[i][j]!=Integer.MAX_VALUE)
					sb.append(adjMatrix[i][j]).append(" ");
				else
					sb.append("0").append(" ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb.toString());
		
	}
}