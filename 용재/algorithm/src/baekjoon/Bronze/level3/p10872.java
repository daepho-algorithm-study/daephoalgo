package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p10872 { // 백준 10872번 문제, 팩토리얼 (조합론)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int ans = 1;
        while (n > 0) {
            ans = ans*n;
            n--;
        }
        System.out.print(ans);
    }
}
