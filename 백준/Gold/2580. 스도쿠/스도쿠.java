import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] board;

    static int[] garo;
    static int[] sero;
    static int[] block;

    static boolean flag;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        board = new int[9][9];

        garo = new int[9];
        sero = new int[9];
        block = new int[9];

        flag = false;

        for(int i = 0; i < 9; i++) {
            String[] str = br.readLine().split(" ");
            for(int j = 0; j < 9; j++) {
                int k = Integer.parseInt(str[j]);

                board[i][j] = k;
                if(k != 0 ) {
                    garo[i] |= (1 << k);
                    sero[j] |= (1 << k);
                    block[i / 3 * 3 + j / 3] |= (1 << k);
                }
            }
        }

        DFS(0, 0);
    }

    private static void DFS(int r, int c) {
        if(flag) {
            return;
        }

        if(r >= 9) {
            flag = true;
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
            return;
        }

        int nr = c == 8 ? r + 1 : r;
        int nc = c == 8 ? 0 : c + 1;

        if(board[r][c] != 0 ) {
            DFS(nr, nc);
        }
        else {
            for(int k = 1; k <= 9; k++) {
                if((garo[r] & (1 << k)) == 0
                        && (sero[c] & (1 << k)) == 0
                        && (block[r / 3 * 3 + c / 3] & (1 << k)) == 0) {
                    board[r][c] = k;
                    garo[r] |= (1 << k);
                    sero[c] |= (1 << k);
                    block[r / 3 * 3 + c / 3] |= (1 << k);

                    DFS(nr, nc);

                    board[r][c] = 0;
                    garo[r] &= ~(1 << k);
                    sero[c] &= ~(1 << k);
                    block[r / 3 * 3 + c / 3] &= ~(1 << k);
                }
            }
        }
    }
}