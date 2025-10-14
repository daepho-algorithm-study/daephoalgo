package SWEA;

import java.io.*;

public class S2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            int n = Integer.parseInt(br.readLine());
            int[][] arr = new int[n][n];

            // 농장 정보 입력 받기
            for (int row = 0; row < n; row++) {
                String info = br.readLine();
                for (int col = 0; col < n; col++) {
//                     arr[row][col] = Integer.parseInt(String.valueOf(info.charAt(col)));
                    arr[row][col] = info.charAt(col) - '0';
                }
            }

            int answer = 0;
            int center = n / 2;

//            for (int i = 0; i < n; i++) {
//                int start, end;
//
//                if (i <= center) {
//                    // 위쪽 절반
//                    start = center - i;
//                    end = center + i;
//                } else {
//                    // 아래쪽 절반
//                    start = i - center;
//                    end = (n - 1) - (i - center);
//                }
//
//                for (int j = start; j <= end; j++) {
//                    answer += arr[i][j];
//                }
//            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (Math.abs(i - center) + Math.abs(j - center) <= center) {
                        answer += arr[i][j];
                    }
                }
            }

            bw.write("#" + test + " " + answer + "\n");
        }

        bw.close();
        br.close();
    }
}

