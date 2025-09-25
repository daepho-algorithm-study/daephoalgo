package baekjoon.Bronze.level2;

import java.util.Scanner;

public class p1152 { // 백준 1152번, 단어의 개수 (문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String words = sc.nextLine();

        int cnt = 0;

        for (int i = 1; i < words.length()-1; i++) {
            if (words.charAt(i) == ' ') {
                cnt++;
            }
        }
        if (words.isEmpty() || words.equals(" ")) {
            System.out.println(0);
            return;
        }
        System.out.println(cnt + 1);

    }
}
