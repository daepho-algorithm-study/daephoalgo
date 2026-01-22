package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p10819 { // 백준 10819번 문제, 차이를 최대로
    static int n;
    static int[] arr;
    static int[] result;
    static boolean[] visited;
    static int maxNum = 0;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        result = new int[n];
        visited = new boolean[n];
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        backtrack(0);

        System.out.print(maxNum);

    }

    static void backtrack(int depth) {
        if (depth == n) {
            int total = 0;
            for (int i = 0; i < n - 1; i++) {
                total += Math.abs(result[i] - result[i + 1]);
            }
            maxNum = Math.max(total, maxNum);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = true;
                result[depth] = arr[j];
                backtrack(depth + 1);
                visited[j] = false;
            }
        }
    }

}
