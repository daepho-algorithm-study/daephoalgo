package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p2720 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt(); // 테스트 케이스
        for (int i = 0; i < t; i++) {
            int c = sc.nextInt(); // 거스름돈 c
            int[] arr = new int[4];
            while (c > 0) {

                if (c >= 25) {
                    arr[0] = c / 25;
                    c = c % 25;
                } else if (25 > c && c >= 10) {
                    arr[1] = c / 10;
                    c = c % 10;
                } else if (10 > c && c >= 5) {
                    arr[2] = c / 5;
                    c = c % 5;
                } else if (5 > c && c >= 1) {
                    arr[3] = c / 1;
                    c = c % 1;
                }
            }
            for (int x : arr) {
                System.out.print(x + " ");
            }
        }
        sc.close();
    }
}
