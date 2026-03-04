package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p2740 { // 백준 2740번 문제, 행렬 곱셈
    static int n, m, a, b; // 행렬 a의 크기 n과 m, 행렬 b의 크기 a와 b
    static int[][] A, B; // 행렬 A,B

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        A = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        B = new int[a][b];
        for (int i = 0; i < a; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < b; j++) {
                B[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 결과 행렬 C의 크기는 a x b
        int[][] C = new int[n][b];

        // 1. C의 행(i)을 하나씩 채움 (0 ~ n-1)
        for (int i = 0; i < n; i++) {

            // 2. C의 열(j)을 하나씩 채움 (0 ~ b-1)
            for (int j = 0; j < b; j++) {

                // 3. A의 행과 B의 열을 짝지어 곱하고 더합니다 (0 ~ m-1)
                for (int k = 0; k < m; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // 4. 결과 출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }

    }
}
