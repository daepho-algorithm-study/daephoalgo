package baekjoon.Bronze.level1;

import java.util.Scanner;

public class p1157 { // 백준 1157번, 단어공부(심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[26]; // 영문자의 개수는 26개임
        String word = sc.next();

        for (int i = 0; i < word.length(); i++) {
            if ('A' <= word.charAt(i) && word.charAt(i) <= 'Z') { // 대문자 범위
                arr[word.charAt(i) - 'A']++; // 해당 인덱스의 값 1 증가
            } else { //소문자 범위
                arr[word.charAt(i) - 'a']++;
            }
        }

        int max = -1;
        char ch = '?';

        for (int i = 0; i < 26; i++) {
            if (arr[i] >max) {
                max = arr[i];
                ch = (char) (i+65); // 대문자 출력이므로 65 더해준다
            } else if (arr[i] == max) {
                ch = '?';
            }
        }

        System.out.println(ch);

        sc.close();
    }
}
