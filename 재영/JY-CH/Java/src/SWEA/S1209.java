package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S1209 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int test = 1; test <= 10; test++) {
            int t = Integer.parseInt(br.readLine());

            int[][] arr = new int[100][100];

            // 배열 입력
            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int maxSum = 0;

            // 행과 열의 합
            for (int i = 0; i < 100; i++) {
                int rowSum = 0;
                int colSum = 0;
                for (int j = 0; j < 100; j++) {
                    rowSum += arr[i][j];
                    colSum += arr[j][i];
                }
                maxSum = Math.max(maxSum, Math.max(rowSum, colSum));
            }

            // 좌하 대각
            int daegak1 = 0;
            for (int i = 0; i < 100; i++) {
                daegak1 += arr[i][i];
            }

            // 우하 대각
            int daegak2 = 0;
            for (int i = 0; i < 100; i++) {
                daegak2 += arr[i][99 - i];
            }

            maxSum = Math.max(maxSum, Math.max(daegak1, daegak2));

            bw.write("#" + t + " " + maxSum + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
