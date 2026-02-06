package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p4158 { // 백준 4158번 문제, CD
    static int n, m;
    static int[] nCd, mCd;
    static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken()); // 상근이
            m = Integer.parseInt(st.nextToken()); // 선영이

            if (n == 0 && m == 0) {
                break;
            }

            result = 0;

            nCd = new int[n]; // 상근이 cd 리스트
            mCd = new int[m]; // 선영이 cd 리스트

            for (int i = 0; i < n; i++) {
                nCd[i] = Integer.parseInt(br.readLine());
            }

            for (int j = 0; j < m; j++) {
                mCd[j] = Integer.parseInt(br.readLine());
                binary(nCd, mCd[j]);
            }

            System.out.println(result);
        }


    }

    static void binary(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target > arr[mid]) {
                start = mid + 1;
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                result++;
                break;
            }
        }
    }
}
