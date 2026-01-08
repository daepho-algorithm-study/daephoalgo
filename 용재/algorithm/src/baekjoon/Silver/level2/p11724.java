package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p11724 { // 백준 11724번 문제, 연결 요소의 개수
    static ArrayList<Integer>[] adj;
    static boolean[] visited ;
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n + 1];
        visited = new boolean[n+1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int j = 0; j < m; j++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            adj[u].add(v);
            adj[v].add(u);
        }
        int total = 0;
        for (int k = 1; k <= n; k++) {
            if (!visited[k]) {
                total++;
                dfs(k);
            }
        }
        System.out.print(total);
    }

    static void dfs(int s) {

        visited[s] = true;
        for (int next : adj[s]) {
            if (!visited[next]) {
                visited[next] = true;
                dfs(next);
            }
        }
    }
}
