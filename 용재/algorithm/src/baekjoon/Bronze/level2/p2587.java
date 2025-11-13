package baekjoon.Bronze.level2;

import java.util.*;
import java.io.*;

public class p2587 { // 백준 2587번 문제, 대표값2 (정렬)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[5];
        int sum=0;
        for (int i = 0; i < 5; ++i) {
            arr[i] = Integer.parseInt(br.readLine());
            sum = sum+arr[i];
        }
        Arrays.sort(arr);
        System.out.println(sum/5);
        System.out.println(arr[2]);
    }
}
