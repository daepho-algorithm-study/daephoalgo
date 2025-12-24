package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p1012 { // 백준 1012번 문제, 유기농 배추

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()); // 가로길이
            int n = Integer.parseInt(st.nextToken()); // 세로길이
            int k = Integer.parseInt(st.nextToken()); // 배추 위치의 개수

            int cnt = 0;

            int[][] yard = new int[n][m];

            for (int i = 0; i < k; i++) { // 배추심기
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken()); // 가로위치 x축 (m축)
                int y = Integer.parseInt(st.nextToken()); // 세로위치 y축 (n축)

                yard[y][x] = 1;
            }
            for (int i = 0; i < yard.length; i++) {
                for (int j = 0; j < yard[i].length; j++) {
                    if (yard[i][j] == 1) {
                        cnt++;
                        yard[i][j] = 2;
                        delta(i, j, yard, n, m);
                    }
                }
            }
            System.out.println(cnt);

        }
    }

    static void delta(int y, int x, int[][] yard, int n, int m) {
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int cx = x + dx[k];
            int cy = y + dy[k];
            if (cx >= 0 && cy >= 0 && cy < n && cx < m) {
                if (yard[cy][cx] == 1) {
                    yard[cy][cx] = 2;
                    delta(cy, cx, yard, n, m);
                }
            }
        }
    }
}
