package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p1260 { // 백준 1260번 문제, DFS와 BFS
    static int n, m, v;
    static ArrayList<Integer>[] adj;
    static boolean[] visitedBfs = new boolean[1001];
    static boolean[] visitedDfs = new boolean[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); // 정점 갯수
        m = Integer.parseInt(st.nextToken()); // 간선 수
        v = Integer.parseInt(st.nextToken()); // 시작할 정점의 번호

        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());
            adj[w].add(u);
            adj[u].add(w);
        }
        // 입력 받은 후 정렬
        for (int i = 1; i <= n; i++) {
            Collections.sort(adj[i]);
        }
        dfs(v);
        System.out.println();
        bfs(v);
    }

    static void dfs(int v) {
        visitedDfs[v] = true;
        System.out.print(v + " ");
        for (int next : adj[v]) {
            if (!visitedDfs[next]) {
                dfs(next);
            }
        }
    }

    static void bfs(int v) {
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visitedBfs[v] = true;
        while (!q.isEmpty()) {
            int w = q.poll();
            System.out.print(w + " ");
            for (int next : adj[w]) {
                if (!visitedBfs[next]) {
                    visitedBfs[next] = true;
                    q.add(next);
                }
            }
        }
    }

}
