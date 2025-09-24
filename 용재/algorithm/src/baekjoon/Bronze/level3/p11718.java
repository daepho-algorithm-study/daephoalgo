package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p11718 { // 백준 11718번 문제, 그대로 출력하기(문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            try {
                String word = sc.nextLine();
                System.out.println(word);

            } catch (Exception e) {
                break;
            }
        }

    }
}
