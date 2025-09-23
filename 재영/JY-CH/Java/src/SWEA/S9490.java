package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S9490 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int i = 1; i <= tc; i++) {

            // 가로 세로 길이
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] arr = new int[n][m];


            // 2차원 배열 정보 담는중
            for (int row = 0; row < n; row++) {
                st = new StringTokenizer(br.readLine());
                for (int col = 0; col < m; col++) {
                    arr[row][col] = Integer.parseInt(st.nextToken());
                }
            }

            // 델타 탐색용 하우상좌
            int[] di = {0, 1, 0, -1};
            int[] dj = {1, 0, -1, 0};

            // 최대값 저장용
            int max = Integer.MIN_VALUE;

            // 최대값을 찾기 위한 델타탐색
            // 이번 풍선팡의 경우 터트린 곳의 값이 추가 range에 들어감
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    int plusRange = arr[j][k];
                    int point = arr[j][k];
                    for (int p = 0; p < 4; p++) {
                        for (int o = 1; o <= plusRange; o++) {
                            int nj = j + di[p] * o;
                            int nk = k + dj[p] * o;


                            if (0 <= nj && nj < n && 0 <= nk && nk < m) {
                                point += arr[nj][nk];;
                            }
                        }
                    }
                    max = Math.max(max, point);
                }


            }
            bw.write("#" + i + " " + max + "\n");
        }
        bw.close();
        br.close();
    }
}
