package baekjoon.Gold.level2;

import java.io.*;
import java.util.*;

public class p1766 { // 백준 1766번 문제, 문제집
    static int n, m; // 문제 수 n , 먼저 풀면 좋은 문제 정보 개수 m
    static int[] degree;
    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        degree = new int[n + 1];
        adj = new ArrayList[n + 1];

        for (int i = 0; i < n + 1; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int j = 0; j < m; j++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            adj[v].add(e);
            degree[e] += 1;
        }
        topologySort();

    }

    static void topologySort() { // 위상정렬 구현
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Integer> q = new PriorityQueue<>(); // 가능하면 낮은난이도 부터 푸는게 좋으므로 우선순위 큐 사용

        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append(" ");

            for (int j = 0; j < adj[now].size(); j++) {
                int next = adj[now].get(j);

                degree[next]--;
                if (degree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        System.out.println(sb);
    }
}
