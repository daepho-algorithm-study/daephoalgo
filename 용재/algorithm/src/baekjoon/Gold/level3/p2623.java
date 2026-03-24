package baekjoon.Gold.level3;

import java.io.*;
import java.util.*;

public class p2623 { // 백준 2623번 문제, 음악프로그램
    static int n, m; // 가수의 수 n, 보조 pd의 수 m
    static ArrayList<Integer>[] arr;
    static int[] degree; // 간선 차수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        degree = new int[n + 1];
        arr = new ArrayList[n + 1];

        for (int i = 0; i < n + 1; i++) {
            arr[i] = new ArrayList<>();
        }

        for (int j = 0; j < m; j++) {
            st = new StringTokenizer(br.readLine());

            int size = Integer.parseInt(st.nextToken()); // 담당한 가수의 수

            int v = Integer.parseInt(st.nextToken());
            for (int k = 0; k < size - 1; k++) {
                int e = Integer.parseInt(st.nextToken());

                arr[v].add(e);
                degree[e]++;

                v = e;
            }
        }

        topologySort();
    }

    static void topologySort() {
        StringBuilder sb = new StringBuilder();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append("\n");

            for (int j = 0; j < arr[now].size(); j++) {
                int next = arr[now].get(j);

                degree[next]--;

                if (degree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        boolean result = true;

        for (int k = 0; k < n + 1; k++) {
            if (degree[k] != 0) {
                result = false;
            }
        }

        System.out.println(result ? sb : 0);
    }
}
