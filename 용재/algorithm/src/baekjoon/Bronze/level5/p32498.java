package baekjoon.Bronze.level5;

import java.io.*;

public class p32498 { // 백준 32498번 문제, Call for Problems
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int result = 0;
        for (int i = 0; i < n; i++) {
            int problem = Integer.parseInt(br.readLine());

            if (problem % 2 == 0) {
                continue;
            } else {
                result++;
            }
        }

        System.out.println(result);

    }
}
