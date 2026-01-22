package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p15649 { // 백준 15649번 문제, N과 M (1)
    static int n, m;
    static int[] result;
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = new int[m];
        arr = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        backtrack(0);

    }

    static void backtrack(int depth) {

        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(result[i]+" ");
            }
            System.out.println();
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = true;
                result[depth] = arr[j];
                backtrack(depth+1);
                visited[j] = false;
            }
        }
    }
}
