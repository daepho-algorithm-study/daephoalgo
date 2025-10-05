package SWEA;

import java.io.*;

public class S4869 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            int n = Integer.parseInt(br.readLine());

            int[] dp = new int[31];
            // 10 * 20 1개
            dp[1] = 1;
            // 20 * 20 1개
            dp[2] = 3;

            int a = n / 10;

            for (int i = 3; i < 31; i++) {
                dp[i] = dp[i-1] + dp[i-2] * 2;
            }

            int answer = dp[a];



            bw.write("#" + test + " " + answer + "\n");





        }

        bw.close();
        br.close();
    }


}
