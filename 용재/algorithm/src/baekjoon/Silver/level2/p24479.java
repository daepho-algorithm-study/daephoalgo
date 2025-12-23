package baekjoon.Silver.level2;

import java.util.*;
import java.io.*;

public class p24479 { // 백준 24479번 문제, 알고리즘 수업 - 깊이 우선 탐색 1

    static ArrayList<Integer>[] adj; // 인접리스트
    static boolean[] visited;
    static int[] order;
    static int count = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 정점 수 n
        int m = Integer.parseInt(st.nextToken()); // 간선수 m
        int r = Integer.parseInt(st.nextToken()); // 시작정점 R

        // 1. 인접 리스트 초기화
        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        visited = new boolean[n + 1];
        order = new int[n + 1];

        // 2.간선 정보 입력
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u); // 무방향이므로 두개 다 추가
        }

        // 3. 오름차순 방문을 위해 정렬(문제 조건)
        for (int i = 1; i <= n; i++) {
            Collections.sort(adj[i]);
        }

        // 4. dfs 시작
        dfs(r);

        // 5. 결과 출력
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < n+1; i++) {
            sb.append(order[i]).append("\n");
        }
        System.out.println(sb);
    }


    static void dfs(int cur) {
        visited[cur] = true; // 현재 노드 방문처리
        order[cur] = count++; // 방문 순서 기록

        // 현재 노드와 연결된 다른 노드들을 확인
        for (int i = 0; i<adj[cur].size(); i++) {
            int next = adj[cur].get(i); // 현재 노드의 인접 리스트에서 i번째 연결된 노드 꺼내기

            if (!visited[next]) {
                dfs(next);
            }
        }


    }
}
