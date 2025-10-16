package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S1204 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int test = 1; test <= T; test++) {

            int testNum = Integer.parseInt(br.readLine());

            int[] range = new int[101];

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 1000; i++) {
                int score = Integer.parseInt(st.nextToken());
                range[score]++;
            }

            int maxNumber = 0;
            int maxScore = 0;

            for (int i = 0; i <= 100; i++) {
                if (range[i] >= maxNumber) {
                    maxNumber = range[i];
                    maxScore = i;
                }
            }

            bw.write("#" + test + " " + maxScore + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
