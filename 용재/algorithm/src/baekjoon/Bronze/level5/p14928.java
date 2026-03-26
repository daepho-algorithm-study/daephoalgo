package baekjoon.Bronze.level5;

import java.io.*;

public class p14928 { // 백준 14928번 문제, 큰 수 (BIG)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String num = br.readLine();
        int number = 0;
        for (int i = 0; i < num.length(); i++) {
            char c = num.charAt(i);
            int toInt = c - '0'; // char를 int로 변환
            int ten = (toInt + 10 * number) % 20000303; // 나머지 출력
            number = ten;
        }
        System.out.println(number);
    }
}
