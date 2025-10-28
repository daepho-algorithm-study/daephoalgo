package SWEA;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class S1210 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        for (int test = 1; test <= 10; test++) {

            int tc = Integer.parseInt(br.readLine());

            int[][] ladder = new int[100][100];


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

            while (y > 0) {
                // 왼쪽으로 갈 수 있으면 쭉
                if (x > 0 && ladder[y][x - 1] == 1) {
                    while (x > 0 && ladder[y][x - 1] == 1) {
                        x--;
                    }
                    // 오른쪽으로 갈 수 있으면 쭉
                } else if (x < 99 && ladder[y][x + 1] == 1) {
                    while (x < 99 && ladder[y][x + 1] == 1) {
                        x++;
                    }
                }
                y--;

            }


            bw.write("#" + test + " " + x + "\n");

        }

        bw.close();
        br.close();
    }
}
