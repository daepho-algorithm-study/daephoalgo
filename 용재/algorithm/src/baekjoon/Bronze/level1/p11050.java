package baekjoon.Bronze.level1;

import java.util.*;
import java.io.*;

public class p11050 { // 백준 11050번 문제, 이항계수 1 (조합론)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // nCk = n! / ((n-k)! *k!)
        System.out.println(factorial(N) / (factorial(N - K) * factorial(K)));
    }

    static int factorial(int N) {
        if (N <= 1) {
            return 1;
        }
        return N * factorial(N - 1);
    }
}
