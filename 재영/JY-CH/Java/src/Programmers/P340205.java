package Programmers;

import java.util.Scanner;

public class P340205 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int answer = 0;

        // for 문 -> while 문으로 수정
        while (number > 0) {
            answer += number % 100;
            number /= 100;
        }

        System.out.println(answer);
    }
}