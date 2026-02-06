package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p2512 { // 백준 2512번 문제, 예산
    static int n, budget;
    static int[] require;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        int maxRequest = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());

        require = new int[n];
        for (int i = 0; i < n; i++) {
            require[i] = Integer.parseInt(st.nextToken());
            // 상한선의 최대값은 요청액중 가장 큰 값으로 잡는다.
            maxRequest = Math.max(maxRequest, require[i]);
        }

        budget = Integer.parseInt(br.readLine());

        // 0원~최대 요청액까지 이분탐색 범위 설정
        int start = 0;
        int end = maxRequest;
        int result = 0;

        while (start <= end) {
            int mid = (start + end) / 2; // 이번에 시도해볼 상한액
            int sum = 0; // 총 지출액

            for (int money : require) {
                // 요청액과 상한액(mid)중 더 작은것을 더한다
                if (money > mid) {
                    sum += mid;
                } else {
                    sum += money;
                }
            }
            if (sum <= budget) {
                // 총 지출액이 예산보다 작으면 예산 안에서 해결 가능함
                // 더 많이 줘도 되는지 확인하기 위해 상한액을 높여봄
                result = mid;
                start = mid + 1;
            } else {
                // 예산 초과함
                // 상한액을 줄여야함
                end = mid - 1;
            }

        }
        System.out.println(result);
    }
}
