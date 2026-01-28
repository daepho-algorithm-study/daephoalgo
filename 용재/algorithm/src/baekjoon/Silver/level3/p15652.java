package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p15652 { // 백준 15652번 문제, N과 M(4)
    static int n, m;
    static int[] result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = new int[m];

        backtrack(0, 1);
    }

    static void backtrack(int depth, int start) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int j = start; j < n + 1; j++) {
            result[depth] = j;
            backtrack(depth + 1, j);
        }
    }
}
