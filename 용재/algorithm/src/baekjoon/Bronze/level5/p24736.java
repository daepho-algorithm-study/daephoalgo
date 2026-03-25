package baekjoon.Bronze.level5;

import java.io.*;
import java.util.*;

public class p24736 { // 백준 24736번 문제, Football Scoring
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken()) * 6;
            int f = Integer.parseInt(st.nextToken()) * 3;
            int s = Integer.parseInt(st.nextToken()) * 2;
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken()) * 2;

            sb.append(t+f+s+p+c).append(" ");
        }
        System.out.println(sb);
    }
}
