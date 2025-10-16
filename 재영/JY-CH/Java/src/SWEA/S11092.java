package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S11092 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            int n = Integer.parseInt(br.readLine());
            int[] nums = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }

            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            int maxIdx = -1;
            int minIdx = -1;

            for (int i = 0; i < n; i++) {
                int num = nums[i];

                if (num < min) {
                    min = num;
                    minIdx = i + 1;
                }

                if (num >= max) {
                    max = num;
                    maxIdx = i + 1;
                }
            }

            int answer = Math.abs(maxIdx - minIdx);
            bw.write("#" + test + " " + answer + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
