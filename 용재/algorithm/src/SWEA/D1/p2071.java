package SWEA.D1;


import java.io.*;
import java.util.*;


public class p2071 { // SWEA 2071번 문제, 평균값 구하기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc < T + 1; tc++) {
            float sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 10; i++) {
                int num = Integer.parseInt(st.nextToken());
                sum += num;
            }

            StringBuilder sb = new StringBuilder();

            sb.append("#").append(tc).append(" ").append(Math.round(sum/10));

            System.out.println(sb);
        }
    }
}
