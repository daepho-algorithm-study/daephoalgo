package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p15650 { // 백준 15650번 문제, N과M -2
    static int n, m;
    static int[] result;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = new int[n];
        visited = new boolean[n];

        backtrack(0, 0);
    }

    static void backtrack(int start, int depth) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int j = start; j < n; j++) {
            if (!visited[j]) {
                visited[j] = true;
                result[depth] = j + 1;
                backtrack(j, depth + 1);
                visited[j] = false;
            }
        }
    }
}
