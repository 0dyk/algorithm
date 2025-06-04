import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N;
    static Line[] lines;
    static int[] parents;

    static class Line {
        int x1, y1;
        int x2, y2;

        public Line(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        lines = new Line[N];
        parents = new int[N];

        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            lines[i] = new Line(
                    Integer.parseInt(str[0]),
                    Integer.parseInt(str[1]),
                    Integer.parseInt(str[2]),
                    Integer.parseInt(str[3])
            );
        }

        for(int i = 0; i < N; ++i) {
            parents[i] = -1;
        }

        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(isCross(lines[i], lines[j])) {
                    union(i, j);
                }
            }
        }

        int answer = 0, maxGroup = 0;

        for(int i = 0; i < N; ++i) {
            if(parents[i] < 0) {
                answer++;
                maxGroup = Math.max(maxGroup, parents[i] * -1);
            }
        }

        System.out.println(answer);
        System.out.println(maxGroup);
    }

    static boolean isCross(Line a, Line b) {
        int k1 = CCW(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1) * CCW(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
        int k2 = CCW(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1) * CCW(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

        if(k1 == 0 && k2 == 0) {
            return Math.max(a.x1, a.x2) >= Math.min(b.x1, b.x2) &&
                    Math.max(b.x1, b.x2) >= Math.min(a.x1, a.x2) &&
                    Math.max(a.y1, a.y2) >= Math.min(b.y1, b.y2) &&
                    Math.max(b.y1, b.y2) >= Math.min(a.y1, a.y2);
        }
        else return k1 <= 0 && k2 <= 0;
    }

    static int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
        long k = (long) (x2 - x1) * (y3 - y1) - (long) (y2 - y1) * (x3 - x1);

        if(k > 0) return 1;
        else if(k < 0) return -1;
        else return 0;
    }

    static int find(int x) {
        if(parents[x] < 0) return x;
        else return parents[x] = find(parents[x]);
    }

    static void union (int aIdx, int bIdx) {
        int fAIdx = find(aIdx);
        int fBIdx = find(bIdx);

        if(fAIdx == fBIdx) return;

        if(parents[fAIdx] <= parents[fBIdx]) {
            parents[fAIdx] += parents[fBIdx];
            parents[fBIdx] = fAIdx;
        }
        else {
            parents[fBIdx] += parents[fAIdx];
            parents[fAIdx] = fBIdx;
        }
    }
}