package baekjoon.Bronze.level2;

import java.util.Scanner;
import java.util.Arrays;

public class p10809 { // 백준 10809번, 알파벳 찾기 (문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int[] arr = new int[26];

        Arrays.fill(arr, -1);

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int index = ch - 'a';

            if (arr[index] == -1) {
                arr[index] = i;
            }
        }
        for (int j = 0; j <arr.length; j++) {
            System.out.print(arr[j] + " ");
        }


    }
}