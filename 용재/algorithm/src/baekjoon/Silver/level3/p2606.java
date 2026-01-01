package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p2606 { // 백준 2606번 문제, 바이러스
    static int n, m;
    static ArrayList<Integer>[] adj;
    static boolean[] visited = new boolean[101];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine()); // 컴퓨터의 수
        m = Integer.parseInt(br.readLine()); // 간선 수

        adj = new ArrayList[n + 1];
        for (int j = 0; j <= n; j++) {
            adj[j] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());

            adj[v].add(u);
            adj[u].add(v);
        }
        System.out.print(dfs(1));
    }

    static Integer dfs(int s) {
        Stack<Integer> stack = new Stack<>();
        stack.add(s); // 시작은 항상 1번
        visited[s] =true;
        int cnt = 0;
        while (!stack.isEmpty()) {
            int w = stack.pop();
            for (int next : adj[w]) {
                if (!visited[next]) {
                    stack.add(next);
                    visited[next] = true;
                    cnt ++;
                }
            }
        }
        return cnt;
    }
}
