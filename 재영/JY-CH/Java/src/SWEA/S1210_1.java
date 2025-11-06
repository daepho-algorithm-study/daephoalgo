package SWEA;

import java.io.*;
import java.util.StringTokenizer;


public class S1210_1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        for (int test = 1; test <= 10; test++) {

            int tc = Integer.parseInt(br.readLine());

            int[][] ladder = new int[100][100];
            int[][] check = new int[100][100];


            // 도착지점은 하나
            // 도착지점에서 역으로 올라가면 1번만 하면된다.
            int endPoint = 0;

            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 100; j++) {
                    ladder[i][j] = Integer.parseInt(st.nextToken());
                    if (ladder[i][j] == 2) {
                        endPoint = j;
                    }
                }
            }

            int x = endPoint;
            int y = 99;

            int[] dx = {-1, 1, 0};
            int[] dy = {0, 0, -1};

            // ladder 델타 풀이
            while (y > 0) {

                // 시작점 체크
                check[y][x] = 1;

                // 좌 우 상 방향으로 순회
                for (int i = 0; i < 3; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // 범위 안에 있고, 다음 좌표가 1이면서, 방문하지 않았다면
                    // y, x 좌표를 현재 좌표로 갱신한다음
                    // check 배열에 방문했음을 표시하고
                    // 현재 반복문을 탈출한다. 1회 이동당 1번씩 한다.
                    if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && ladder[ny][nx] == 1 && check[ny][nx] == 0) {
                        x = nx;
                        y = ny;
                        check[ny][nx] = 1;
                        break;
                    }


                }

            }


            bw.write("#" + test + " " + x + "\n");

        }

        bw.close();
        br.close();
    }
}
