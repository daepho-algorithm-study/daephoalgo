package baekjoon.Bronze.level2;

import java.io.*;
import java.util.*;

public class p14614 { // 백준 14614번 문제, Calculate!
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        String c = st.nextToken();

        int num = Integer.valueOf(c.charAt(c.length()-1)) - '0';

        if (num % 2 != 0) {
            a = a^b;
        }

        System.out.println(a);
    }
}
