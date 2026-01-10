package baekjoon.Gold.level4;

import java.io.*;
import java.util.*;

public class p1707 { // 백준 1707번 문제, 이분 그래프
    static int K, V, E;
    static ArrayList<Integer>[] adj;
    static int[] visited;
    static boolean flag; // 이분그래프 판별

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        K = Integer.parseInt(br.readLine()); // 테스트 케이스 수

        for (int tc = 0; tc < K; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            flag = true;

            V = Integer.parseInt(st.nextToken()); // 그래프 정점의 수
            E = Integer.parseInt(st.nextToken()); // 간선의 개수

            visited = new int[V + 1];
            adj = new ArrayList[V + 1];
            for (int i = 0; i <= V; i++) {
                adj[i] = new ArrayList<>();
            }

            for (int j = 0; j < E; j++) {
                st = new StringTokenizer(br.readLine());

                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                adj[u].add(v);
                adj[v].add(u);
            }

            for (int k = 1; k <= V; k++) {
                if (visited[k] == 0) { // 방문하지 않은 모든 정점에 대해 색칠
                    graph(k, 1);
                }
            }
            System.out.println(flag ? "YES" : "NO");
        }
    } // main

    static void graph(int cur, int color) { // 이분 그래프 판별 함수
        visited[cur] = color;

        for (int next : adj[cur]) {
            if (visited[next] == 0) { // 방문한적 없으면
                graph(next, color == 1 ? 2 : 1); // 색이 1이면 2 아니면 1
                // 현재와 다른 색을 칠하고
            } else {
                if (visited[next] == visited[cur]) {
                    flag = false; // 연결된 정점이 현재 정점과 색이 같으면 이분 그래프가 아님
                }
            }
        }


    }
}
