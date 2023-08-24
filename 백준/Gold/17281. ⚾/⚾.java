import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[][] seonsu = new int[N + 1][9 + 1];

		
		for (int i = 1; i <= N; i++) {
			String[] str = br.readLine().split(" ");
			for (int j = 1; j <= 9; j++) {
				seonsu[i][j] = Integer.parseInt(str[j - 1]);
			}
		}

		int[] orders = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		int maxScore = 0;

		do {
			if (orders[3] != 1) continue;

			int idx = 0;
			int score = 0;

			for (int ining = 1; ining <= N; ining++) {

				int[] base = { 0, 0, 0, 0 };
				int outCount = 0;

				while (outCount != 3) {
					int tmpseonsu = seonsu[ining][orders[idx]];

					switch (tmpseonsu) {
					case 0:
						outCount++;
						break;
					case 1:
						if (base[3] == 1) { base[3] = 0; score++; }
						if (base[2] == 1) { base[3] = 1; base[2] = 0; }
						if (base[1] == 1) { base[2] = 1; base[1] = 0; }
						base[1] = 1;
						break;

					case 2:
						if (base[3] == 1) { base[3] = 0; score++; }
						if (base[2] == 1) { base[2] = 0; score++; }
						if (base[1] == 1) { base[3] = 1; base[1] = 0; }
						base[2] = 1;
						break;

					case 3:
						if (base[3] == 1) { base[3] = 0; score++; }
						if (base[2] == 1) { base[2] = 0; score++; }
						if (base[1] == 1) { base[1] = 0; score++; }
						base[3] = 1;
						break;

					case 4:
						if (base[3] == 1) { base[3] = 0; score++; }
						if (base[2] == 1) { base[2] = 0; score++; }
						if (base[1] == 1) { base[1] = 0; score++; }
						score++;
						break;
					}

					idx = (idx + 1) % 9;
				}
			}

			if (maxScore < score) maxScore = score;

		} while (np(orders));

		System.out.println(maxScore);
	}

	private static boolean np(int[] input) {

		int n = input.length;

		// step 1. 뒤쪽부터 꼭대기를 찾는다. (꼭대기 바로 앞이 교환할 자리)
		int i = n - 1;
		while (i > 0 && input[i - 1] >= input[i]) { i--; }

		if (i == 0) {  // 가장 큰 순열의 형태이므로 종료!
			return false;
		}

		// step 2. 꼭대기 바로 앞(i - 1) 자리에 교환할 값을 뒤쪽부터 찾는다.
		int j = n - 1;
		while (input[i - 1] >= input[j]) { j--; }

		// step 3. 꼭대기 바로 앞(i - 1) 자리와 그 자리 값보다 한단계 큰 자리(j) 수와 교환
		swap(input, i - 1, j);

		// step 4. 꼭대기부터 맨 뒤까지 오름차순으로 정렬
		int k = n - 1;
		while (i < k) {
			swap(input, i++, k--);
		}

		return true;
	}

	private static void swap(int[] input, int i, int j) {
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
}