package baekjoon.Silver.level5;

import java.util.Scanner;

public class p25206 { // 백준 25206번, 너의 평점은 (심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        float ans = 0;
        float sum = 0;
        for (int tc = 0; tc < 20; tc++) {
            String name = sc.next();
            Float num = sc.nextFloat();
            String score = sc.next();
            sum += num;
            if (score.equals("A+")) {
                ans += num * 4.5;
            } else if (score.equals("A0")) {
                ans += num * 4.0;
            } else if (score.equals("B+")) {
                ans += num * 3.5;
            } else if (score.equals("B0")) {
                ans += num * 3.0;
            } else if (score.equals("C+")) {
                ans += num * 2.5;
            } else if (score.equals("C0")) {
                ans += num * 2.0;
            } else if (score.equals("D+")) {
                ans += num * 1.5;
            } else if (score.equals("D0")) {
                ans += num * 1.0;
            } else if (score.equals("F")) {
                ans += num * 0;
            } else{
                sum -= num;
                continue;
            }
        }
        System.out.println(ans / sum);
    }
}
