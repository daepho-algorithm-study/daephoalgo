package baekjoon.Bronze.level2;

import java.util.Scanner;

public class p2745 { // 백준 2745번 문제, 진법 변환 (수학 1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String n = sc.next(); // 바꿔야 할 n
        int b = sc.nextInt(); // B 진법

        sc.close(); // 닫는거 생활화 하자

        int tmp = 1;
        int sum = 0;

        for (int i = n.length() - 1; i >= 0; i--) { // x 진법은 젤 오른쪽 부터 계산해야한다
            char c = n.charAt(i);

            if ('A' <= c && c <= 'z') {
                sum += (c - 'A' + 10) * tmp; // 아스키 코드 생각하면 문자 - 'A' 하면 최소 0 ~ 최대 26나옴 근데 10진법 이상에서는 'A'는 10임
            } else {
                sum += (c - '0') * tmp; // char 형태끼리의 비교기 때문에 -'0' 해야함 안그럼 char * int라 성립안됨
            }
            tmp *= b; // 제곱으로 늘기 때문
        }
        System.out.print(sum);

    }
}
