package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S9489 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            // 배열 크기
            int[][] arr = new int[n][m];

            // 배열 정보 채우기
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }


            int answer = 0;

            // 핵심은 연속 되어있지 않을 경우 카운트를 초기화 하는것.
            // 가로 체크
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == 1) {
                        cnt++;
                    } else {
                        if (cnt > answer) {
                            answer = cnt;
                        }
                        cnt = 0;
                    }
                }
                if (cnt > answer) {
                    answer = cnt;
                }
            }

            // 세로 체크
            // 세로 체크이고, 가로 세로 길이가 입력값에 따라 달라져
            // m , n의 위치를 잘 확인하고 넣을 것
            for (int i = 0; i < m; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == 1) {
                        cnt++;
                    } else {
                        if (cnt > answer) {
                            answer = cnt;
                        }
                        cnt = 0;
                    }
                }
                if (cnt > answer) {
                    answer = cnt;
                }
            }

            bw.write("#" + test + " " + answer + "\n");

        }


        bw.close();
        br.close();
    }


}
