package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p7795 { // 백준 7795번 문제, 먹을 것인가 먹힐 것인가
    static int n, m;
    static int[] arr, arr2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            arr = new int[n];
            arr2 = new int[m];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr2[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr2);

            int result = 0;
            for (int k = 0; k < n; k++) {
                result += binary(arr[k], arr2);
            }

            System.out.println(result);
        }
    }

    static int binary(int target, int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int idx = 0; // 1개도 없을 수 있기 때문에 0으로 시작

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] < target) {
                // arr[mid]가 target 보다 작다 = 0번부터 arr[mid] 까지는 전부 먹을 수 있다
                start = mid + 1; //
                idx = mid + 1; // 갯수 저장
            } else {
                end = mid - 1;
            }
        }

        return idx;
    }

}
