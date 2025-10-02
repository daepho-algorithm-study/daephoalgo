package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S12712 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            // 가로 세로 길이, 분사 세기
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] arr = new int[n][n];


            // 2차원 배열 정보 담는중
            for (int row = 0; row < n; row++) {
                st = new StringTokenizer(br.readLine());
                for (int col = 0; col < n; col++) {
                    arr[row][col] = Integer.parseInt(st.nextToken());
                }
            }

            // 델타 탐색용 하우상좌
            int[] di = {0, 1, 0, -1};
            int[] dj = {1, 0, -1, 0};

            // 최대값 저장용
            int maxCross = Integer.MIN_VALUE;

            // 최대값을 찾기 위한 델타탐색
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int plusRange = m;
                    int point = arr[j][k];
                    for (int p = 0; p < 4; p++) {
                        for (int o = 1; o < plusRange; o++) {
                            int nj = j + di[p] * o;
                            int nk = k + dj[p] * o;


                            if (0 <= nj && nj < n && 0 <= nk && nk < n) {
                                point += arr[nj][nk];
                                ;
                            }
                        }
                    }
                    maxCross = Math.max(maxCross, point);
                }
            }

            // 델타 탐색용  11, 1, 5, 7
            int[] di2 = {-1, -1, 1, 1};
            int[] dj2 = {-1, 1, 1, -1};

            // 최대값 저장용
            int maxX = Integer.MIN_VALUE;

            // 최대값을 찾기 위한 델타탐색
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int plusRange = m;
                    int point = arr[j][k];
                    for (int p = 0; p < 4; p++) {
                        for (int o = 1; o < plusRange; o++) {
                            int nj = j + di2[p] * o;
                            int nk = k + dj2[p] * o;


                            if (0 <= nj && nj < n && 0 <= nk && nk < n) {
                                point += arr[nj][nk];
                                ;
                            }
                        }
                    }
                    maxX = Math.max(maxX, point);
                }
            }

            // 십자, 대각중 젤 많은거 가져오기
            int answer = Math.max(maxX, maxCross);

            bw.write("#" + test + " " + answer + "\n");

        }

        bw.close();
        br.close();
    }


}
