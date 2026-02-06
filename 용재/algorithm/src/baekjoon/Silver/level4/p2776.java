package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p2776 { // 백준 2776번 문제, 암기왕
    static int n, m;
    static int[] arr, arr2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            m = Integer.parseInt(br.readLine());
            arr2 = new int[m];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr2[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr);

            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < m; k++) {
                sb.append(binary(arr, arr2[k])).append("\n");
            }
            System.out.print(sb);
        }
    }

    static int binary(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] == target) {
                return 1;
            }

            if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return 0;
    }
}
