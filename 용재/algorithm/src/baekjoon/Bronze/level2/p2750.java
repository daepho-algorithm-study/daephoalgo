package baekjoon.Bronze.level2;

import java.util.*;
import java.io.*;

public class p2750 { // 백준 2750번 문제, 수 정렬하기 (정렬)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);

        for (int j = 0; j < n; j++) {
            System.out.println(arr[j]);
        }
    }
}
