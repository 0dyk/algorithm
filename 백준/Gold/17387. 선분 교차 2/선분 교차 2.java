import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static class Point {
        int x;
        int y;
        public Point (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        Point p1 = new Point(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
        Point p2 = new Point(Integer.parseInt(str[2]), Integer.parseInt(str[3]));

        str = br.readLine().split(" ");
        Point p3 = new Point(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
        Point p4 = new Point(Integer.parseInt(str[2]), Integer.parseInt(str[3]));

        /**************************************************/

        int answer = 0;

        int k1 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
        int k2 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

        if(k1 == 0 && k2 == 0) {
            if (Math.max(p1.x, p2.x) >= Math.min(p3.x, p4.x) &&
                    Math.max(p3.x, p4.x) >= Math.min(p1.x, p2.x) &&
                    Math.max(p1.y, p2.y) >= Math.min(p3.y, p4.y) &&
                    Math.max(p3.y, p4.y) >= Math.min(p1.y, p2.y)) {
                answer = 1;
            }
        } else if (k1 <= 0 && k2 <= 0) {
            answer = 1;
        }

        System.out.println(answer);
    }

    static int CCW (Point p1, Point p2, Point p3) {
        long ret = (long)(p2.x - p1.x) * (p3.y - p1.y) - (long)(p2.y - p1.y) * (p3.x - p1.x);

        if(ret > 0) return 1;
        else if (ret < 0) return -1;
        else return 0;
    }
}