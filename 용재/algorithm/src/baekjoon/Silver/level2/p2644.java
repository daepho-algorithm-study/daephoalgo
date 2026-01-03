package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p2644 { // 백준 2644번 문제, 촌수계산
    static int n, m;
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine()); // 전체 사람의 수
        StringTokenizer st = new StringTokenizer(br.readLine());

        int s = Integer.parseInt(st.nextToken()); // 시작 노드
        int e = Integer.parseInt(st.nextToken()); // 종료 노드, 편의상 s,e로 구분했으나 계산해야하는 촌수+방향이 없기때문에 바껴도됨

        m = Integer.parseInt(br.readLine());

        visited = new boolean[n + 1];
        adj = new ArrayList[n + 1];

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
        dfs(s, e, 0);
        if (ans == 0) {
            System.out.println(-1);
        } else {
            System.out.print(ans);
        }
    }

    static void dfs(int s, int e, int level) {
        if (s == e) {
            ans = level;
            return;
        }
        visited[s] =true;
        for (int next : adj[s]) {
            if (!visited[next]) {
                dfs(next, e, level + 1);

            }
        }
    }
}
