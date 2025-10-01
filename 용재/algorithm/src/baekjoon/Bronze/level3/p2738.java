package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p2738 { // 백준 2738번, 행렬 덧셈(2차원 배열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        int[][] arr2 = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr2[i][j] = sc.nextInt();
            }
        }
        int[][] ans = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = arr[i][j] + arr2[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != m - 1) {
                    System.out.print(ans[i][j] + " ");
                } else {
                    System.out.print(ans[i][j] + "\n");
                }
            }
        }
    }
}
