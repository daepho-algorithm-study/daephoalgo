package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p2903 { // 백준 2903번 문제, 중앙 이동 알고리즘 (수학 1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int dot = 2;

        for (int i = 0; i < n; i++) {
            dot = dot * 2 - 1;
        }

        System.out.print(dot * dot);
    }
}
