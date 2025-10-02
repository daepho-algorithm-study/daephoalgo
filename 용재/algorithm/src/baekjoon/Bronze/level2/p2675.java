package baekjoon.Bronze.level2;

import java.util.*;
import java.lang.*;

public class p2675 { // 백준 2675번, 문자열 반복(문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int r =sc.nextInt();
            String s = sc.next();

            StringBuilder sb = new StringBuilder();

            for (char c : s.toCharArray()) {
                /* String.valuOf(c) 로 문자를 문자열로 바꾸고 repeat(r) 로 r 번 반복 */
                sb.append(String.valueOf(c).repeat(r));
            }
            System.out.println(sb.toString());
        }
    }
}