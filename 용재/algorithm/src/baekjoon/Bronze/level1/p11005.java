package baekjoon.Bronze.level1;

import java.util.Scanner;

public class p11005 { // 백준 11005번 문제, 진법 변환 2 (수학 1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int b = sc.nextInt();

        sc.close();

        StringBuilder sb = new StringBuilder();// 문자 추가는 StringBuilder가 효율적

        // n 이 0이 될 때 까지 반복
        while (n > 0) {
            // 나누기 전에 먼저 나머지 구한다
            int tmp = n % b;

            if (10 <= tmp) {
                // 나머지가 10 이상이면 'A' 부터 시작하는 문자로 변환
                sb.append((char) (tmp - 10 + 'A'));
            } else {
                // 나머지가 10 미만이면 0부터 시작하는 문자
                sb.append((char) (tmp + '0'));
            }
            // 이제 n을 b로 나누고 다음 계산에 사용
            n = n / b;
        }

        System.out.println(sb.reverse());
    }
}
