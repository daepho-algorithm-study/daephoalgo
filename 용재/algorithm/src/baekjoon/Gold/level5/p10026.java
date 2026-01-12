package baekjoon.Gold.level5;

import java.io.*;
import java.util.*;

public class p10026 { // 백준 10026번 문제, 적록색약
    static int n;
    static char[][] grid;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        grid = new char[n][n];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        for (int tc = 0; tc < 2; tc++) {
            int cnt = 0;
            visited = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!visited[i][j]) {
                        colorBlind(i, j, grid[i][j]);
                        cnt++;
                    }
                    if (tc == 0) {
                        if (grid[i][j] == 'G') {
                            grid[i][j] = 'R';
                        }
                    }
                }
            }
            bw.write(String.valueOf(cnt) + " ");
        }
        bw.flush();

        br.close();
        bw.close();

    }

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static void colorBlind(int si, int sj, char color) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{si, sj});
        visited[si][sj] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int ci = cur[0];
            int cj = cur[1];
            for (int k = 0; k < 4; k++) {
                int nx = cj + dx[k];
                int ny = ci + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if (!visited[ny][nx] && grid[ny][nx] == color) {
                        queue.add(new int[]{ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
}
