package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S18575 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int i = 1; i <= tc; i++) {

            // 배열 1변 크기
            int range = Integer.parseInt(br.readLine());
            // 2차원 배열 크기
            int[][] arr = new int[range][range];


            // 2차원 배열 정보 담는중
            for (int row = 0; row < range; row++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int col = 0; col < range; col++) {
                    arr[row][col] = Integer.parseInt(st.nextToken());
                }
            }

            // 델타 탐색용 하우상좌
            int[] di = {0, 1 ,0, -1};
            int[] dj = {1, 0 ,-1, 0};

            // 최대 최소값 저장용
            int max = 0;
            int min = 999999999;

            // 최대값 최소값을 찾기 위한 델타탐색
            for (int j = 0; j < range; j++) {
                for (int k = 0; k < range; k++) {
                    int point = arr[j][k];
                    for (int m = 0; m < 4; m++) {
                        for (int n = 1; n <= range; n++) {
                            int nj = j + di[m] * n;
                            int nk = k + dj[m] * n;


                            if (0 <= nj && nj < range && 0 <= nk && nk < range) {
                                point += arr[nj][nk];
                            }
                        }
                    }
                    if (max < point) {
                        max = point;
                    } else if (min > point) {
                        min = point;
                    }
                }
            }

            int answer = max - min;

            bw.write("#" + i + " " + answer + "\n");
        }
        bw.close();
        br.close();
    }
}
