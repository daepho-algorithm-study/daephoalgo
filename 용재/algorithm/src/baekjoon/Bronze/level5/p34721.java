package baekjoon.Bronze.level5;

import java.io.*;

public class p34721 { // 백준 34721번 문제, 역사를 걸으면 동국이 보이고
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            sb.append("I love DGU").append("\n");
        }
        System.out.print(sb);

    }
}
