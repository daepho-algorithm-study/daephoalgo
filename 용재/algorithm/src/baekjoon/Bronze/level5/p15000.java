package baekjoon.Bronze.level5;

import java.io.*;

public class p15000 { // 백준 15000번 문제, CAPS
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String words = br.readLine();

        String ans = words.toUpperCase();

        System.out.println(ans);
    }
}
