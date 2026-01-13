package baekjoon.Gold.level4;

import java.io.*;
import java.util.*;

public class p2573 { // 백준 2573번 문제, 빙산
    static int n, m;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int time = 0;
        while (true) {
            // 1. 빙산 덩어리 개수 세기
            int landCount = countIslands();

            // 2. 종료 조건 체크
            if (landCount >= 2) { // 덩어리가 2개 이상이면 현재 시간 출력
                System.out.println(time);
                break;
            }
            if (landCount == 0) { // 다 녹을 때까지 분리되지 않으면 0
                System.out.println(0);
                break;
            }

            // 3. 빙산 녹이기 (시간 경과)
            melt();
            time++;
        }
    }

    // 덩어리 개수 세는 함수
    static int countIslands() {
        visited = new boolean[n][m];
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 빙산이면서 아직 방문 안 한 곳만 탐색 시작
                if (map[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j); // 연결된 빙산들 다 방문 처리
                    count++;   // 덩어리 1개 추가
                }
            }
        }
        return count;
    }

    // 연결된 빙산 탐색
    static void bfs(int si, int sj) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{si, sj});
        visited[si][sj] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cy = cur[0];
            int cx = cur[1];

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (map[ny][nx] != 0 && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        q.add(new int[]{ny, nx});
                    }
                }
            }
        }
    }

    // 빙산 녹이기 로직
    static void melt() {
        int[][] meltCount = new int[n][m]; // 이번 턴에 녹을 양을 저장할 배열

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != 0) {
                    // 4방향 중 바다(0)의 개수 세기
                    int seaCnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                            if (map[ny][nx] == 0) {
                                seaCnt++;
                            }
                        }
                    }
                    meltCount[i][j] = seaCnt;
                }
            }
        }

        // 계산이 다 끝난 후 한꺼번에 반영
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0) {
                    map[i][j] -= meltCount[i][j];
                    if (map[i][j] < 0) {
                        map[i][j] = 0; // 음수 방지
                    }
                }
            }
        }
    }
}