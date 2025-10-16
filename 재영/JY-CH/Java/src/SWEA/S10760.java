package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S10760 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine()); // 테스트 케이스 수

        for (int test = 1; test <= T; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); // 행
            int M = Integer.parseInt(st.nextToken()); // 열

            int[][] land = new int[N][M];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    land[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
            int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

            int cnt = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    int currentPos = land[i][j];
                    int low = 0;

                    for (int d = 0; d < 8; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            if (land[ni][nj] < currentPos) {
                                low++;
                            }
                        }
                    }

                    if (low >= 4) {
                        cnt++;
                    }
                }
            }

            bw.write("#" + test + " " + cnt + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}