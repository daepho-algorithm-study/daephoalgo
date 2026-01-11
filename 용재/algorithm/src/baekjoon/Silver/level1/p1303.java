package baekjoon.Silver.level1;

import java.util.*;
import java.io.*;

public class p1303 { // 백준 1303번 문제, 전쟁 - 전투
    static int n, m;
    static char[][] soldiers;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        soldiers = new char[m][n];
        visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            String line = br.readLine();
            for (int j = 0; j < line.length(); j++) {
                soldiers[i][j] = line.charAt(j);
            }
        }
        int myTeam = 0;
        int enemy = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (soldiers[i][j] == 'W') {
                        myTeam += powers(i, j, 'W');
                    } else {
                        enemy += powers(i, j, 'B');
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(myTeam).append(" ").append(enemy);
        System.out.print(sb);
    }

    static int powers(int si, int sj, char color) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int power = 1; // 들어온 순간 1이므로
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{si, sj});
        visited[si][sj] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cy = cur[0];
            int cx = cur[1];

            for (int k = 0; k < 4; k++) {
                int ny = cy + dy[k];
                int nx = cx + dx[k];
                if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                    if (!visited[ny][nx] && soldiers[ny][nx] == color) {
                        q.add(new int[]{ny, nx});
                        visited[ny][nx] = true;
                        power++;
                    }
                }
            }
        }
        return power * power;
    }
}
