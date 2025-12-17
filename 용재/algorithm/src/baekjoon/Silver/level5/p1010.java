package baekjoon.Silver.level5;

import java.util.*;
import java.io.*;

public class p1010 { // 백준 1010번 문제, 다리놓기 (조합론)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        // DP 테이블 미리 생성 (입력 최대값이 30 미만이므로)
        // dp[M][N] : M개 중 N개를 뽑는 경우의 수
        int[][] dp = new int[30][30];

        // 1. 초기값 세팅
        for (int i = 0; i < 30; i++) {
            dp[i][i] = 1; // nCn = 1
            dp[i][0] = 1; // nC0 = 1 (문제에선 N>=1 이지만 점화식을 위해)
        }

        // 2. 점화식으로 테이블 채우기
        for (int i = 2; i < 30; i++) {
            for (int j = 1; j < 30; j++) {
                // 공식: nCr = n-1Cr-1 + n-1Cr
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            // M개 중에 N개를 뽑는 경우의 수 출력
            sb.append(dp[M][N]).append('\n');
        }
        System.out.println(sb);
    }
}
