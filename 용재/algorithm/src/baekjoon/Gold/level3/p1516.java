package baekjoon.Gold.level3;

import java.io.*;
import java.util.*;

public class p1516 { // 백준 1516번 문제, 게임 개발
    static int n; // 건물의 종류 수
    static int[] degree, times; // 관계차수, 건물짓는데 걸리는 시간
    static ArrayList<Integer>[] adj; // 건물이 지어지는 순서

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        degree = new int[n + 1];
        times = new int[n + 1];
        adj = new ArrayList[n + 1];

        for (int k = 0; k < n + 1; k++) {
            adj[k] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken()); // 처음껀 건물을 짓기위해 걸리는 시간
            times[i + 1] = time; // 처음 들어오는건 시간임

            int v = Integer.parseInt(st.nextToken());
            while (v != -1) {

                int e = Integer.parseInt(st.nextToken());
                adj[v].add(i + 1);
                degree[i + 1]++;
                v = e; // 순서대로 하기위해서 기존 v에 e를 재할당
                if (e == -1) { // -1이 들어오면 다음 줄로 넘어가야함
                    break;
                }

            }
        }

        topologySort();
    }

    static void topologySort() {
        int[] dp = new int[n + 1]; // 각 건물이 지어지는데 걸리는 시간을 기록할 dp
        Queue<Integer> q = new LinkedList<>(); // 지어질 건물

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < n + 1; i++) {
            dp[i] = times[i]; // 일단 자기 자신을 짓는 시간을 체크
            if (degree[i] == 0) {
                q.offer(i); // 건물을 큐에 넣음
            }
        }
        while (!q.isEmpty()) {
            int now = q.poll();

            for (int j = 0; j < adj[now].size(); j++) {
                int next = adj[now].get(j);

                // next의 완료 시간 vs now 시간 + next 건물의 순수 건축시간
                dp[next] = Math.max(dp[next], dp[now] + times[next]);

                degree[next]--;
                if (degree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        for (int k = 1; k < n + 1; k++) {
            sb.append(dp[k]).append("\n");
        }
        System.out.println(sb);
    }
}
