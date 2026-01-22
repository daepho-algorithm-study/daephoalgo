package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p1182 { // 백준 1182번 문제, 부분수열의 합
    static int n, s;
    static int[] arr;
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        sequence(0, 0);

        // s가 0일 경우 공집합(아무것도 안 골랐을 때)도 합이 0이라 카운트되서 -1해줌
        // why? 문제에서 크기가 양수인 부분수열중에서 s가 되는값을 찾으랬음
        if (s == 0) {
            System.out.println(cnt - 1);
        } else {
            System.out.println(cnt);
        }
    }

    static void sequence(int total, int depth) {

        if (depth == n) {
            if (total == s) {
                cnt++;
            }
            return;
        }

        // 1. 현재 인덱스의 원소를 선택하는 경우
        sequence(total + arr[depth],depth + 1);

        // 2. 현재 인덱스의 원소를 선택하지 않는 경우
        sequence(total,depth + 1);


    }


}
