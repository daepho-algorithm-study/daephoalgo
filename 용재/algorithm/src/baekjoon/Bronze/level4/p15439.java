package baekjoon.Bronze.level4;

import java.util.Scanner;

public class p15439 { // 백준 15349번 문제, 베라의 패션 (조합론)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());

        System.out.println(N * (N - 1));

    }
}
