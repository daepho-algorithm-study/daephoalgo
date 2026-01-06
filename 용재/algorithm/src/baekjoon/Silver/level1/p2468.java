package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p2468 { // 백준 2468번 문제, 안전 영역
    static int n;
    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        int maxHeight = 0;
        // 지도 초기화
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int high = Integer.parseInt(st.nextToken());
                map[i][j] = high;
                maxHeight = Math.max(maxHeight, high); // 최대 높이 갱신
            }
        }

        int maxSafeArea = 0;
        for (int k = 0; k <= 100; k++) {
            visited = new boolean[n][n]; // k가 바뀔 때 마다 방문배열 다시 초기화
            int safeArea = 0; // k 별 안전 섬 갯수
            if (k > maxHeight) { // 만약 최고 높이보다 k가 높아지면 어차피 0이라 더이상 탐색 x
                break;
            }
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    if (map[y][x] > k && !visited[y][x]) {
                        safeArea++;
                        bfs(k, y, x);
                    }

                }
            }
            maxSafeArea = Math.max(maxSafeArea, safeArea); // 최다 안전 섬 갱신
        }

        System.out.print(maxSafeArea);
    }

    static void bfs(int height, int sy, int sx) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{sy, sx});
        visited[sy][sx] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cy = cur[0];
            int cx = cur[1];
            for (int k = 0; k < 4; k++) {
                int ny = cy + dy[k];
                int nx = cx + dx[k];

                if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                    if (map[ny][nx] > height && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        q.add(new int[]{ny, nx});
                    }
                }
            }
        }
    }

}
