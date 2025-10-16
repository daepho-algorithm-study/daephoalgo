package SWEA;

import java.io.*;
import java.util.StringTokenizer;


public class S2001 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] arr = new int[n][n];

            // 배열 입력 받기
            for (int row = 0; row < n; row++) {
                st = new StringTokenizer(br.readLine());
                for (int col = 0; col < n; col++) {
                    arr[row][col] = Integer.parseInt(st.nextToken());
                }
            }

            int answer = Integer.MIN_VALUE;

            //범위 내의 합 구하기
            for (int i = 0; i <= n - m; i++) {
                for (int j = 0; j <= n - m; j++) {
                    int point = 0;
                    for (int x = 0; x < m; x++) {
                        for (int y = 0; y < m; y++) {
                            point += arr[i + x][j + y];
                        }
                    }
                    answer = Math.max(answer, point);
                }
            }

            bw.write("#" + test + " " + answer + "\n");
        }

        bw.close();
        br.close();
    }
}
