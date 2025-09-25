package SWEA;

import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class S1974 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            int[][] arr = new int[9][9];


            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 9; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // 맞으면 1 그대로 던짐
            // 아니면 0을 바꿈
            int answer = 1;

            // set를 이용해서 비교할 생각
            // 가로줄
            for (int i = 0; i < 9; i++) {
                Set<Integer> check = new HashSet<>();
                for (int j = 0; j < 9; j++) {
                    check.add(arr[i][j]);
                }
                if (check.size() != 9) {
                    answer = 0;
                }
            }

            // 세로줄
            for (int i = 0; i < 9; i++) {
                Set<Integer> check2 = new HashSet<>();
                for (int j = 0; j < 9; j++) {
                    check2.add(arr[j][i]);
                }
                if (check2.size() != 9) {
                    answer = 0;
                }
            }


            // 3 * 3 9번씩 돌면서 체크

            int[] sudoku_col = {0,3,6, 0,3,6, 0,3,6};
            int[] sudoku_row = {0,0,0, 3,3,3, 6,6,6};


            for (int i = 0; i < 9; i++) {
                Set<Integer> check3 = new HashSet<>();
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        int nj = j + sudoku_col[i];
                        int nk = k + sudoku_row[i];
                        check3.add(arr[nj][nk]);
                    }
                }
                if (check3.size() != 9) {
                    answer = 0;
                }
            }

            bw.write("#" + test + " " + answer + "\n");
        }


        bw.close();
        br.close();
    }
}

