package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p1920 { // 백준 1920번 문제, 수 찾기
    static int n, m;
    static int[] arr, arr2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

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

        for (int k = 0; k < m; k++) {
            System.out.println(binarySearch(arr,arr2[k]));
        }
    }

    static int binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] == target) {
                return 1; // 찾음
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
    }

}
