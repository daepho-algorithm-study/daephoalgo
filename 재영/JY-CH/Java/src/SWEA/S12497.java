package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S12497 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            int n = Integer.parseInt(br.readLine());

            int[][] colorOrder = new int[n][5];
            int[][] field = new int[10][10];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 5; j++) {
                    colorOrder[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int answer = 0;

            for (int i = 0; i < n; i++) {
                int col1 = colorOrder[i][0];
                int row1 = colorOrder[i][1];
                int col2 = colorOrder[i][2];
                int row2 = colorOrder[i][3];
                int color = colorOrder[i][4];
                for (int j = col1; j <= col2; j++) {
                    for (int k = row1; k <= row2; k++) {
                        if (field[j][k] == 0) {
                            field[j][k] = color;
                        } else if (field[j][k] != 0 && field[j][k] != color) {
                            field[j][k] = 3;
                        }
                    }
                }
            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (field[i][j] == 3) {
                        answer++;
                    }
                }
            }

            bw.write("#" + test + " " + answer + "\n");

        }


        bw.close();
        br.close();
    }


}
