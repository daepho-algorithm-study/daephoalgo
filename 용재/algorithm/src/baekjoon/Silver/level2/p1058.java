package baekjoon.Silver.level2;

import java.util.*;
import java.io.*;

public class p1058 { // 백준 1058번 문제, 친구
    static int n;
    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine()); // 사람 수

        adj = new ArrayList[n + 1];
        for (int k = 0; k <= n; k++) {
            adj[k] = new ArrayList<>();
        }

        for (int i = 1; i <= n; i++) {
            String friends = br.readLine();
            for (int j = 0; j < n; j++) {
                char friend = friends.charAt(j);

                if (friend == 'Y') {
                    adj[i].add(j + 1);
                }
            }
        }
        int maxFriends = 0; // 가장 유명한 사람의 2-친구 수

        // 모든 사람(1~N)에 대해 각각 BFS
        for (int i = 1; i <= n; i++) {
            // visited는 매 사람마다 새로 필요
            // i라는 사람을 기준으로 했을 때의 방문 여부이기 때문
            maxFriends = Math.max(maxFriends, bfs(i));
        }

        System.out.print(maxFriends);

    }

    // startNode로부터 거리가 2 이하인 친구들을 찾는 함수
    static int bfs(int startNode) {
        boolean[] visited = new boolean[n + 1];
        Queue<int[]> q = new LinkedList<>(); // {노드번호, 깊이}를 저장

        q.offer(new int[]{startNode, 0}); // 시작점, 깊이 0
        visited[startNode] = true;

        int count = 0;

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int node = current[0];
            int depth = current[1];

            // 깊이가 2 이상이면 더 이상 친구의 친구를 찾지 않음 (친구의 친구의 친구는 X)
            if (depth >= 2) {
                continue;
            }

            // 현재 노드와 연결된 친구들 탐색
            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.offer(new int[]{next, depth + 1}); // 깊이를 1 늘려서 큐에 넣음
                    count++; // 방문한 친구 수 증가
                }
            }
        }

        return count;
    }
}
