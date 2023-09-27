import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N;	// 정점의 수
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int adjMatrix[][] = new int[N][N];
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			
			adjMatrix[a][b] = 1;
			adjMatrix[b][a] = 1;
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(i==j)continue;
					if(adjMatrix[i][k]>0 && adjMatrix[k][j]>0 && (adjMatrix[i][j]==0 || adjMatrix[i][j] > adjMatrix[i][k]+adjMatrix[k][j] ))
						adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
				}
			}
		}
		
		int answer = 0;
		int minKB = Integer.MAX_VALUE;
		for(int i=0; i<N; i++) {
			int sum = 0;
			for(int j=0; j<N; j++) {
				sum += adjMatrix[i][j];
			}
			if(sum<minKB) {
				minKB = sum;
				answer = i;
			}
		}
		
		System.out.println(answer+1);
	}
}