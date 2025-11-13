package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p2751 { // 백준 2751번 문제, 수 정렬하기 2 (정렬)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        for (int j = 0; j < arr.length; j++) {
            System.out.println(arr[j]);
        }
    }
}
