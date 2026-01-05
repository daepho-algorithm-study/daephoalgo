package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p4963 { // 백준 4963번 문제, 섬의 개수
    static int w, h;
    static int[][] map;
    static boolean[][] visited;
    static int count;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken()); // 너비
            h = Integer.parseInt(st.nextToken()); // 높이

            if (w == 0 && h == 0) {
                break; // 입출력의 마지막은 0이 두개 주어짐
            }
            map = new int[h][w];
            visited = new boolean[h][w];
            count = 0;
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 1 && !visited[i][j]) {
                        delta(i, j);
                    }
                }
            }

            System.out.println(count);
        }
    }

    static void delta(int si, int sj) {
        Stack<int[]> stack = new Stack<>();
        stack.add(new int[]{si, sj});
        int[] dx = {0, 1, 0, -1, 1, 1, -1, -1};
        int[] dy = {1, 0, -1, 0, 1, -1, 1, -1}; // 8방향 탐색
        while (!stack.isEmpty()) {
            int[] cur = stack.pop();

            int cy = cur[0];
            int cx = cur[1];

            for (int k = 0; k < 8; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
                    if (!visited[ny][nx] && map[ny][nx] == 1) {
                        visited[ny][nx] = true;
                        stack.add(new int[]{ny, nx});
                    }
                }
            }
        }

        count++; // 함수에 들어왔다는것 = 섬이 최소 1개는 있다. 이므로 visited로 다 체크 한 뒤에 count 올려준다.
    }

}
