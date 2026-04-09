package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p11047 { // 백준 11047번 문제, 동전 0
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 동전의 종류 N
        int k = Integer.parseInt(st.nextToken()); // 가치의 합 K

        int[] coins = new int[10];

        for (int i = 0; i < n; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        int now = 0;
        int cnt = n - 1;
        int result = 0;
        while (now != k) {

            if (now < k) {
                now += coins[cnt];
                result++;
            }

            if (now > k) {
                now -= coins[cnt];
                result--;
                cnt--;
            }
        }

        System.out.println(result);
    }
}
