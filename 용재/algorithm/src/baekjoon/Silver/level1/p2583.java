package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p2583 { // 백준 2483번 문제, 영역구하기
    static int m, n, k;
    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[m][n];
        visited = new boolean[m][n];

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            for (int y = y1; y < y2; y++) {
                for (int x = x1; x < x2; x++) {
                    map[y][x] = 1; // 맵 초기화
                }
            }
        }

        int total = 0; // 섬의 갯수
        ArrayList<Integer> lands = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                if (map[i][j] == 0 && !visited[i][j]) {
                    total++;
                    cnt = dfs(i, j);
                    lands.add(cnt);
                }
            }
        }

        Collections.sort(lands);

        for (int land : lands) {
            sb.append(land).append(" ");
        }

        System.out.println(total);
        System.out.print(sb);
    }

    static int dfs(int sy, int sx) {

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        Stack<int[]> stack = new Stack<>();
        stack.add(new int[]{sy, sx});
        visited[sy][sx] = true;
        int size = 0;

        while (!stack.isEmpty()) {
            int[] cur = stack.pop();
            int cy = cur[0];
            int cx = cur[1];
            size++;

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (!visited[ny][nx] && map[ny][nx] == 0) {
                        visited[ny][nx] = true;
                        stack.add(new int[]{ny, nx});
                    }
                }
            }
        }

        return size;
    }
}
