package baekjoon.Bronze.level4;

import java.io.*;

public class p15873 { // 백준 15873번 문제, 공백 없는 A+B
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String nums = br.readLine();
        int a = 0;
        int b = 0;

        if (nums.length() > 2) {
            // A와 B의 범위는 10 이하라 3자리 넘어가면 둘 중 하나는 무조건 10임
            if (nums.charAt(1) == '0') {
                a = 10; // 두번째 자리가 0이면 a = 10임
                if (nums.length() == 3) {
                    b = Integer.valueOf(nums.charAt(2) - '0');
                } else {
                    b = 10;
                }
            } else {
                b = 10; // 두 번째 자리가 0이 아니면 210 처럼 b가 10임
                if (nums.length() == 3) {
                    a = Integer.valueOf(nums.charAt(0) - '0');
                } else {
                    a = 10;
                }
            }
        } else {
            a = Integer.valueOf(nums.charAt(0) - '0');
            b = Integer.valueOf(nums.charAt(1) - '0');
        }

        System.out.println(a + b);
    }
}
