import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int C, N, Q;
    static String[] color;
    static Set<String> nickname;
    static Node ROOT_NODE;

    static class Node {
        char c;
        boolean isLast;
        Node[] child;

        public Node(char c) {
            this.c = c;
            this.isLast = false;
            this.child = new Node[26];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        ROOT_NODE = new Node('*');

        String[] str = br.readLine().split(" ");
        C = Integer.parseInt(str[0]);
        N = Integer.parseInt(str[1]);

        color = new String[C];
        nickname = new HashSet<>();

        for(int i = 0; i < C; ++i) {
            String str2 = br.readLine();
            addTrieNode(str2);
        }

        for(int i = 0; i < N; ++i) {
            nickname.add(br.readLine());
        }

        Q = Integer.parseInt(br.readLine());
        for(int i = 0; i < Q; ++i) {
            sb.append(isPrize(br.readLine())).append("\n");
        }

        System.out.print(sb);
    }

    static String isPrize(String str) {
        Node cur = ROOT_NODE;

        for(int i = 0; i < str.length(); ++i) {
            int idx = str.charAt(i) - 'a';

            if(cur.child[idx] != null) {
                cur = cur.child[idx];

                if(cur.isLast && nickname.contains(str.substring(i + 1))) {
                    return "Yes";
                }
            }
            else {
                break;
            }
        }

        return "No";
    }

    static void addTrieNode(String str) {
        Node cur = ROOT_NODE;

        for(int i = 0; i < str.length(); ++i) {
            int idx = str.charAt(i) - 'a';

            if(cur.child[idx] != null) {
                cur = cur.child[idx];
            }
            else {
                Node newNode = new Node(str.charAt(i));
                cur.child[idx] = newNode;
                cur = newNode;
            }
        }

        cur.isLast = true;
    }
}