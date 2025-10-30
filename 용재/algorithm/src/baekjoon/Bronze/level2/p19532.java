package baekjoon.Bronze.level2;

import java.io.*;
import java.util.StringTokenizer;

public class p19532 { // 백준 19532번 문제, 수학은 비대면 강의 입니다. (브루트 포스)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int f = Integer.parseInt(st.nextToken());

        // ax + by = c
        // dx + ey = f
        int ansX = -9999;
        int ansY = -9999;
        for (int x = -999; x < 1000; x++) {
            for (int y = -999; y < 1000; y++) {
                if (a * x + b * y == c && d * x + e * y == f) {
                    ansX = x;
                    ansY = y;
                    break;
                }
            }
            if (ansX != -9999) {
                break;
            }
        }
        System.out.println(ansX + " " + ansY);

    }
}
