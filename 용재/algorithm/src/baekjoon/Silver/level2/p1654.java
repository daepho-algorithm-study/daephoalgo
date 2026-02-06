package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p1654 { // 백준 1654번 문제, 랜선 자르기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[] arr = new int[K];
        long max = 0; // 랜선 길이는 2^31-1까지 가능하므로 long 써야함..

        for (int i = 0; i < K; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if (max < arr[i]) {
                max = arr[i];
            }
        }

        long start = 1;
        long end = max;

        while (start <= end) {
            long mid = (start + end) / 2;
            long count = 0;

            for (int i = 0; i < K; i++) {
                count += (arr[i] / mid);
            }

            if (count >= N) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        System.out.println(end);
    }
}
