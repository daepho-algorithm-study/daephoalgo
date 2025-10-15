package baekjoon.Bronze.level3;

import java.io.*;
import java.util.*;

public class p2501 { // 백준 2501번 문제, 약수 구하기 (약수, 배수와 소수 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        br.close();

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                if (cnt == k) {
                    System.out.println(i);
                    break;
                }
            }
        }
        if(cnt <k) {
            System.out.println(0);
        }
    }
}
