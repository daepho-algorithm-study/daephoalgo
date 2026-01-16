package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p1743 { // 백준 1743번 문제, 음식물 피하기
    static int r, c, k;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken()); // 통로의 세로 길이
        c = Integer.parseInt(st.nextToken()); // 통로의 가로 길이
        k = Integer.parseInt(st.nextToken()); // 음식물 쓰레기의 개수

        map = new int[r][c];
        visited = new boolean[r][c];

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            map[row-1][col-1] = 1;
        }

        int maxSizeArea = 0;
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                int AreaSize = 0;
                if (!visited[x][y] && map[x][y]==1){
                    AreaSize = bfs(x,y);
                }
                maxSizeArea = Math.max(maxSizeArea, AreaSize);
            }
        }
        System.out.print(maxSizeArea);
    }

    static int bfs(int si, int sj) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{si, sj});
        int count = 0;
        visited[si][sj] = true;
        while (!q.isEmpty()) {
            count++;
            int[] cur = q.poll();
            int ci = cur[0];
            int cj = cur[1];

            for (int k = 0; k < 4; k++) {
                int ni = ci + dy[k];
                int nj = cj + dx[k];
                if (ni >= 0 && nj >= 0 && ni < r && nj < c) {
                    if (!visited[ni][nj] && map[ni][nj] == 1) {
                        visited[ni][nj] = true;
                        q.add(new int[]{ni, nj});
                    }
                }
            }
        }
        return count;
    }
}
