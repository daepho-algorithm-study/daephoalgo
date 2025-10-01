package baekjoon.Silver.level5;

import java.util.Scanner;

public class p2563 { // 백준 2563번, 색종이 (2차원 배열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] arr = new int[100][100];
        int tc = sc.nextInt();
        int ans = 0;
        for (int t = 0; t < tc; t++) {

            int x = sc.nextInt();
            int y = sc.nextInt();

            for (int i = x; i < x + 10; i++) {
                for (int j = y; j < y + 10; j++) {
                    arr[i][j] += 1;
                }
            }
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (arr[i][j] != 0) {
                    ans++;
                }
            }
        }
        System.out.print(ans);
    }
}
