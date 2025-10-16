package baekjoon.Bronze.level2;

import java.util.Scanner;

public class p2292 { // 백준 2292번 문제, 벌집 (수학 1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int cnt = 1;
        int range = 1;

        if (n == 1) {
            System.out.print(1);
        } else {
            while (range < n) {
                range = range + (6 * cnt);
                cnt++;
            }
            System.out.print(cnt);
        }

    }
}
