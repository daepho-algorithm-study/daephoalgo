package baekjoon.Gold.level5;

import java.util.*;
import java.io.*;

public class p13023 { // 백준 13023번 문제, ABCDE
    static int n, m;
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static boolean flag = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n];
        visited = new boolean[n];

        for (int j = 0; j < n; j++) {
            adj[j] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            adj[u].add(v);
            adj[v].add(u);
        }
        for (int k = 0; k < n; k++) {
            dfs(k, 1);
            if (flag) {
                break;
            }
        }


        int ans = flag ? 1 : 0;
        System.out.println(ans);
    }

    static void dfs(int s, int depth) {

        if (flag) {
            return; // 이미 찾았으면 더이상 탐색 x
        }

        if (depth == 5) { // 깊이 5가 되면 끝
            flag = true;
            return;
        }

        visited[s] = true;

        for (int next : adj[s]) {
            if (!visited[next]) {
                dfs(next, depth + 1); // 깊이 추가하며 재귀
            }
        }
        // 백트래킹
        visited[s] = false;
    }
}
