package baekjoon.Bronze.level3;

import java.util.*;
import java.io.*;

public class p14215 { // 백준 14215번, 세 막대 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());


        if (a >= b && a >= c) {
            while (b + c <= a) {
                a--;
            }
        } else if (b >= a && b >= c) {
            while (a + c <= b) {
                b--;
            }
        } else if (c >= a && c >= b) {
            while (a + b <= c) {
                c--;
            }
        }

        int ans = a + b + c;

        System.out.println(ans);
    }
}
