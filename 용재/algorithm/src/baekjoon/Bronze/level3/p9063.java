package baekjoon.Bronze.level3;

import java.util.*;
import java.io.*;

public class p9063 { // 백준 9063번 문제, 대지 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] A = new int[n];
        int[] B = new int[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());

        }

        Arrays.sort(A);
        Arrays.sort(B);

        int ans = (A[n-1]-A[0]) * (B[n-1] - B[0]);

        System.out.println(ans);
        br.close();

    }
}

