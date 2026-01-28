package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p2805 { // 백준 2805 문제, 나무 자르기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 나무 수
        int M = Integer.parseInt(st.nextToken()); // 필요한 나무 길이

        int[] trees = new int[N];
        long max = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            trees[i] = Integer.parseInt(st.nextToken());
            if (max < trees[i]) {
                max = trees[i];
            }
        }

        long start = 0; // 나무 높이는 0부터 시작 가능
        long end = max;

        while (start <= end) {
            long mid = (start + end) / 2;
            long sum = 0;

            // 잘린 나무 길이 합 구하기
            for (int tree : trees) {
                // 나무가 절단기보다 높을 때만 잘림
                if (tree > mid) {
                    sum += (tree - mid);
                }
            }

            // 필요한 M미터보다 많이 가져갔나?
            if (sum >= M) {
                // 너무 많이 잘랐거나 딱 맞음 -> 절단기 높이를 높여서 나무를 아끼자
                start = mid + 1;
            } else {
                // 나무가 부족함 -> 절단기 높이를 낮춰서 더 많이 베어야 함
                end = mid - 1;
            }
        }

        System.out.println(end);
    }
}
