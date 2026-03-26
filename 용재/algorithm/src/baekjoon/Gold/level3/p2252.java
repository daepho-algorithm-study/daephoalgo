package baekjoon.Gold.level3;

import java.io.*;
import java.util.*;

public class p2252 { // 백준 2252번 문제, 줄 세우기
    static int n, m;
    static int[] degree; // 진입 차수
    static ArrayList<Integer>[] node; // 간선 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        degree = new int[n + 1];

        node = new ArrayList[n + 1];

        for (int k = 0; k < n + 1; k++) {
            node[k] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int v = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            node[v].add(e); // 간선 넣기
            degree[e] += 1; // 간선 배열 존재하면 진입차수 더해주기
        }
        topologySort();
    }

    static void topologySort() {
        Queue<Integer> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append(" ");

            for (int j = 0; j < node[now].size(); j++) {
                int next = node[now].get(j);

                degree[next]--;

                if (degree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        System.out.println(sb);
    }
}
