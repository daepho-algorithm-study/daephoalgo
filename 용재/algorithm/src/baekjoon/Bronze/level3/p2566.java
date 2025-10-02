package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p2566 { // 백준 2566번 문제, 최댓값 (2차원 배열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[9][9];
        int max = -1;
        int row = 0;
        int col = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int num = sc.nextInt();
                arr[i][j] = num;

                if (arr[i][j] > max) {
                    max = arr[i][j];
                    row = i+1;
                    col = j+1;
                }
            }
        }
        System.out.println(max);
        System.out.println(row + " " + col);
    }
}
