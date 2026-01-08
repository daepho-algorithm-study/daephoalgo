package baekjoon.Silver.level2;

import java.util.*;
import java.io.*;

public class p13565 { // 백준 13565번 문제, 침투
    static int n, m;
    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken()); // 세로
        n = Integer.parseInt(st.nextToken()); // 가로

        map = new int[m][n];
        visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                char c = line.charAt(j);
                if (c == '1') {
                    map[i][j] = 1;
                } else {
                    map[i][j] = 0;
                }
            }
        }

        boolean flag = false;
        for (int j = 0; j < n; j++) {
            if (map[0][j] == 0) { // 첫줄에서 전류가 통하면 bfs 시작
                flag = bfs(j);
                if (flag) { // flag가 true가 되면 종료 (전류가 통한다는것이기 때문)
                    break;
                }
            }
        }

        if (flag) {
            System.out.print("YES");
        } else {
            System.out.print("NO");
        }
    }

    static boolean bfs(int s) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, s});
        visited[0][s] = true;

        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cy = cur[0];
            int cx = cur[1];

            for (int k = 0; k < 4; k++) {
                int ny = cy + dy[k];
                int nx = cx + dx[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (!visited[ny][nx] && map[ny][nx] == 0) {
                        visited[ny][nx] = true;
                        if (ny == m-1) { // true = 갈 수 있다이므로 m-1번 인덱스까지 도달하면 끝까지 갔다는것이기에 return
                            return true;
                        }
                        q.add(new int[]{ny, nx});
                    }
                }

            }
        }

        return false; // while문 끝났다 -> 체크 다 했는데 최하단 인덱스까지 도달하지 못했다 = 전류 안통함
    }
}
