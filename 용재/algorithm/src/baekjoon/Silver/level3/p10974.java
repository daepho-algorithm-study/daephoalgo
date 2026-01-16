package baekjoon.Silver.level3;

import java.io.*;


public class p10974 { // 백준 10974번 문제, 모든 순열
    static int n;
    static int[] result;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        result = new int[n];
        visited = new boolean[n];
        back(0);
        System.out.println(sb);
    }

    static void back(int depth) {
        if (depth == n) {
            for (int j = 0; j < result.length; j++) {
                sb.append(result[j]).append(" ");
            }
            sb.append("\n");
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result[depth] = i + 1;
                back(depth + 1);
                visited[i] = false;
            }
        }
    }
}
