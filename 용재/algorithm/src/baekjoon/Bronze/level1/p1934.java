package baekjoon.Bronze.level1;

import java.io.*;
import java.util.*;

public class p1934 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 테스트 케이스 개수 입력
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            // 최소공배수 = (A * B) / 최대공약수
            int result = (A * B) / gcd(A, B);
            sb.append(result).append('\n');
        }

        System.out.println(sb);
    }

    // 최대공약수(GCD) 구하는 함수 (유클리드 호제법 - 반복문 방식)
    public static int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}
