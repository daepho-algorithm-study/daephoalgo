package baekjoon.Bronze.level3;

import java.util.Scanner;

public class p10988 { // 백준 10988문제 , 팰린드롬인지 확인하기 (심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.next();

        int ans = 1;
        for (int i = 0; i < word.length() / 2; i++) {
            if (word.charAt(i) == word.charAt(word.length() - i - 1)) {
                ans = 1;
            } else {
                ans = 0;
                break;
            }
        }
        System.out.println(ans);


        sc.close();

    }
}
