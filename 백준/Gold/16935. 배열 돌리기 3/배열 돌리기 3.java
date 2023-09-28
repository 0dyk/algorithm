import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N, M, R, K;
	static int[][] arr;

	// 1
	public static void upDown() {
		int[][] tmp = new int[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = arr[N - 1 - i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}

	// 2
	public static void leftRight() {
		int[][] tmp = new int[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = arr[i][M - 1 - j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}

	// 4 :: 3은 * 3
	public static void leftRotate() {

		int[][] tmp = new int[M][N];
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				tmp[i][j] = arr[j][M - 1 - i];
			}
		}

		arr = new int[M][N];
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = tmp[i][j];
			}
		}

		int t = N;
		N = M;
		M = t;
	}

	// 6 :: 5은 3번 실행
	public static void quarter() {
		int tmp;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmp = arr[i][j];
				arr[i][j] = arr[i][j + M / 2];
				arr[i][j + M / 2] = arr[i + N / 2][j + M / 2];
				arr[i + N / 2][j + M / 2] = arr[i + N / 2][j];
				arr[i + N / 2][j] = tmp;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		N = Integer.parseInt(str[0]);
		M = Integer.parseInt(str[1]);
		R = Integer.parseInt(str[2]);

		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(str[j]);
			}
		}

		str = br.readLine().split(" ");
		/********** input **********/

		for (int t = 0; t < str.length; t++) {
			K = Integer.parseInt(str[t]);
			switch (K) {
			case 1:
				upDown();
				break;
			case 2:
				leftRight();
				break;
			case 3:
				for (int p = 0; p < 3; p++)
					leftRotate();
				break;
			case 4:
				leftRotate();
				break;
			case 5:
				for (int p = 0; p < 3; p++)
					quarter();
				break;
			case 6:
				quarter();
				break;
			}
		}

		/********** solve **********/

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(arr[i][j]);
				if (j != M - 1)
					sb.append(" ");
				else
					sb.append("\n");
			}
		}

		System.out.println(sb);
	}
}