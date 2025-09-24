package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p2444 { // 백준 2444번 문제, 별 찍기-7(심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String blank = "";
            String star = "";

            for (int j = n - i; j > 1; j--) {
                blank += " ";
            }
            for (int k = 0; k < i; k++) {
                star += "*";
            }
            System.out.println(blank + star + "*" + star);
        }

        for (int i = n - 2; i > -1; i--) {
            String blank = "";
            String star = "";

            for (int j = 1; j < n - i; j++) {
                blank += " ";
            }
            for (int k = i; k > 0; k--) {
                star += "*";
            }
            System.out.println(blank + star + "*" + star);
        }
    }
}
