package baekjoon.Bronze.level5;

import java.util.Scanner;

public class p3003 { // 백준 3003번 문제, 킹,퀸,룩,비숍,나이트,폰 (심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[]{1, 1, 2, 2, 2, 8};
        int ans = 0;

        for (int i = 0; i < 6; i++) {
            int a = sc.nextInt();

            arr[i] = arr[i] - a;
            System.out.print(arr[i] + " ");
        }
    }
}
