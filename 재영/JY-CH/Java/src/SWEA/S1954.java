package SWEA;

import java.io.*;

public class S1954 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            int n = Integer.parseInt(br.readLine());

            int[][] arr = new int[n][n];

            // 순서를 잘 생각하자
            // 수를 채워넣어야된다
            // 근데 델타를 이용해서 채워넣어야한다.

            int[] dx = {1, 0, -1, 0};
            int[] dy = {0, 1, 0, -1};
            int dir = 0; // 오른쪽

            int x = 0, y = 0;
            for (int i = 1; i <= n * n; i++) {
                arr[x][y] = i;

                int nx = x + dx[dir];
                int ny = y + dy[dir];

                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0) {
                    x = nx;
                    y = ny;
                } else {
                    // 방향 전환하는법
                    // 그때도 못했고 지금도 생각 못했음
                    // 이거 못하면 문제 못품
                    dir = (dir + 1) % 4;
                    x += dx[dir];
                    y += dy[dir];
                }
            }

            bw.write("#" + test + "\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
        }

        bw.close();
        br.close();
    }
}

