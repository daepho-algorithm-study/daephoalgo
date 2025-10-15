package baekjoon.Bronze.level3;

import java.io.*;
import java.util.*;

public class p1085 { // 백준 1085번 문제, 직사각형에서 탈출 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        int min = 9999;

        if (w - x < min) {
            min = w - x;
        }

        if (h - y < min) {
            min = h - y;
        }

        if (x < min) {
            min = x;
        }

        if (y < min) {
            min = y;
        }
        System.out.print(min);
    }
}
