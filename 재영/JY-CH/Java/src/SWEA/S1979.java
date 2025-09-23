package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S1979 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            // 배열 크기
            int[][] arr = new int[n][n];

            // 배열 정보 채우기
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }


            int answer = 0;

            // 핵심은 연속 되어있지 않을 경우 카운트를 초기화 하는것.
            // 가로 체크
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] == 1) {
                        cnt++;
                    } else {
                        if (cnt == k) {
                            answer++;
                        }
                        cnt = 0;
                    }
                }
                if (cnt == k) {
                    answer++;
                }
            }

            // 세로 체크
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == 1) {
                        cnt++;
                    } else {
                        if (cnt == k) {
                            answer++;
                        }
                        cnt = 0;
                    }
                }
                if (cnt == k) {
                    answer++;
                }
            }

                bw.write("#" + test + " " + answer + "\n");

            }


            bw.close();
            br.close();
        }


    }
