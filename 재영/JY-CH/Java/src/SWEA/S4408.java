package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S4408 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {


            int n = Integer.parseInt(br.readLine());

            // 방이 200개씩 마주보고 있음
            // 복도라는 공간도 200개 있다고 생각하고
            // 누적합을 이용해 풀이할 생각
            int[] way = new int[201];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());

                // 혹시 모를 2번째 입력값이 클 경우
                // 앞선 변수명이 잘못된거 같음;;
                int startWay = (Math.min(start, end) + 1) / 2;
                int endWay = (Math.max(start, end) + 1) / 2;

                for (int j = startWay; j <= endWay; j++) {
                    way[j]++;
                }

            }

            int answer = 0;

            for (int i = 1; i <= 200; i++) {
                answer = Math.max(answer, way[i]);
            }


            bw.write("#" + test + " " + answer + "\n");



        }


        bw.close();
        br.close();
    }


}
