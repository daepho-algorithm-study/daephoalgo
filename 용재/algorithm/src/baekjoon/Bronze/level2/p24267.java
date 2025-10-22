package baekjoon.Bronze.level2;

import java.io.*;

public class p24267 { // 백준 24267번 문제, 알고리즘 수업 - 알고리즘의 수행시간 6 (시간 복잡도)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(br.readLine());
//        long ans = 0; 시간초과남
//        long cnt = 0;
//        while (cnt < n - 2) {
//            cnt++;
//            for (int i = 1; i <= cnt; i++) {
//                ans += i;
//            }
//        }

        System.out.println((n*(n-1)*(n-2))/6);
        System.out.println("3");
    }
}
