package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p15651 { // 백준 15651번 문제, N과 M (3)
    static int n, m;
    static int[] result;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        result = new int[m];

        backtrack(0);
        System.out.print(sb);
    }

    static void backtrack(int depth) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                sb.append(result[i]).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int j = 0; j < n; j++) {
            result[depth] = j+1;
            backtrack(depth+1);
        }
    }
}
