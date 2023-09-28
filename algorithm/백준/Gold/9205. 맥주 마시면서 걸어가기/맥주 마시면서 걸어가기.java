import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int tc=1; tc<=T; tc++) {
			// 입력 받기
			int N = Integer.parseInt(in.readLine());
			int V = N+2;
			int beers = 20;	// 보유 중인 맥주 개수
			
			int pos[][] = new int[N+2][2];
			
			StringTokenizer st = new StringTokenizer(in.readLine());
			pos[0][0] = Integer.parseInt(st.nextToken());
			pos[0][1] = Integer.parseInt(st.nextToken());
			
			for(int i=1; i<N+1; i++) {
				st = new StringTokenizer(in.readLine());
				pos[i][0] = Integer.parseInt(st.nextToken());
				pos[i][1] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(in.readLine());
			pos[N+1][0] = Integer.parseInt(st.nextToken());
			pos[N+1][1] = Integer.parseInt(st.nextToken());
			
			
			// 인접행렬 생성
			int[][] adjMatrix = new int[N+2][N+2];
			
			for(int i=0; i<V; i++) {
				for(int j=0; j<V; j++) {
					if(dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) <= 1000) {
						adjMatrix[i][j] = 1;
					}
				}
			}
			
			// 플로이드 워셜
			for(int k=0; k<N+2; k++) {
				for(int i=0; i<N+2; i++) {
					for(int j=0; j<N+2; j++) {
						if(adjMatrix[i][k] == 1 && adjMatrix[k][j] == 1) {
							adjMatrix[i][j] = 1;
						}
					}
				}
			}
			if(adjMatrix[0][N+1] > 0)
				out.write("happy\n");
			else
				out.write("sad\n");
		}
		
		out.close();
	}
	static int dist(int sy, int sx, int ey, int ex) {
		return Math.abs(ey-sy)+Math.abs(ex-sx);
	}
}