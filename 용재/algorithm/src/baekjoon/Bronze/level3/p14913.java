package baekjoon.Bronze.level3;

import java.io.*;
import java.util.*;

public class p14913 { // 백준 14913번 문제, 등차수열에서 항 번호 찾기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken()); // 첫 항 a
        int d = Integer.parseInt(st.nextToken()); // 공차 d
        int k = Integer.parseInt(st.nextToken()); // 찾는 수 k

        int cnt = ((k - a) / d) + 1;

        int left = (k - a) % d;

        if (left == 0 && cnt >0) {
            System.out.println(cnt);
        } else {
            System.out.println("X");
        }


    }
}