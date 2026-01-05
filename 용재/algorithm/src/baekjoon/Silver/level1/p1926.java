package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p1926 {
    static int n, m;
    static int[][] draw;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); // 세로
        m = Integer.parseInt(st.nextToken()); // 가로
        draw = new int[n][m];
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) { // 맵 초기화
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                draw[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int maxCount = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && draw[i][j] == 1) {
                    total++;
                    maxCount = Integer.max(maxCount, dfs(i, j));
                }
            }
        }
        System.out.println(total);
        System.out.println(maxCount);
    }

    static int dfs(int sy, int sx) {
        Stack<int[]> stack = new Stack<>();
        stack.add(new int[]{sy, sx});
        visited[sy][sx] = true;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int cnt =0;
        while (!stack.isEmpty()) {
            int[] cur = stack.pop();
            int cy = cur[0];
            int cx = cur[1];
            cnt++;

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (!visited[ny][nx] && draw[ny][nx] == 1) {
                        visited[ny][nx] = true;
                        stack.add(new int[] {ny,nx});
                    }
                }
            }
        }
        return cnt;
    }

}
