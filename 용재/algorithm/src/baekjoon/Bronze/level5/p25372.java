package baekjoon.Bronze.level5;

import java.io.*;

public class p25372 { // 백준 25372번 문제, 성택이의 은밀한 비밀번호
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {

            String password = br.readLine();

            if (password.length() > 5 && password.length() < 10) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

    }
}
