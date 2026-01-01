package baekjoon.Gold.level4;

import java.io.*;
import java.util.*;

public class p2636 {
    static int col, row;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<int[]> cheese = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());

        col = Integer.parseInt(st.nextToken()); // 세로
        row = Integer.parseInt(st.nextToken()); // 가로

        int[][] map = new int[col][row];
        for (int i = 0; i < col; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < row; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;
        int time = 0;
        int count = 0;
        while (true) {
            count = bfs(map, cheese);
            if(count == 0) {
                break;
            }
            ans = count;
            time++;

            cheese.clear();
        }
        System.out.println(time);
        System.out.println(ans);
    }

    static Integer bfs(int[][] map, ArrayList<int[]> cheese) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[col][row];
        visited[0][0] = true;
        q.add(new int[]{0, 0});
        int cnt = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int y = cur[0];
            int x = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        if (map[ny][nx] == 0) {
                            q.add(new int[]{ny, nx});
                        } else {
                            cheese.add(new int[]{ny, nx});
                            map[ny][nx] = 0;
                            cnt++;
                        }
                    }
                }
            }

        }

        return cnt;
    }
}
