package baekjoon.Bronze.level3;

import java.io.*;

public class p24265 { // 백준 24265번 문제, 알고리즘 수업 - 알고리즘의 수행시간 4 (시간 복잡도)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Integer.parseInt(br.readLine());

        System.out.println((n*(n - 1) / 2));
        System.out.println(2);
    }
}
