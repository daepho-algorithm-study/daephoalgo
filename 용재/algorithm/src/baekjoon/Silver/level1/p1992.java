package baekjoon.Silver.level1;

import java.io.*;

public class p1992 { // 백준 1992번 문제, 쿼드트리
    static int[][] data;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); // N은 언제나 2의 제곱수

        data = new int[n][n];
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                data[i][j] = line.charAt(j) - '0';
            }
        }

        slice(0, 0, n);

        System.out.println(sb);
    }


    static void slice(int row, int col, int size) {
        int color = data[row][col];

        if (check(row, col, size)) { // 한 영역의 색이 모두 같은지 체크
            if (color == 0) {
                sb.append(0); // 0이면 0 적기
            } else {
                sb.append(1); // 1이면 1적기
            }
            return; // 전부 같으면 재귀 종료
        }

        // 전부 같지 않은 경우
        int newSize = size / 2; // 절반씩 나누어가며 탐색

        sb.append('('); // 새로 들어갈때 괄호해야함
        slice(row, col, newSize); // 1사분면 (왼쪽 위)
        slice(row, col + newSize, newSize); // 2사분면 (오른쪽 위)
        slice(row + newSize, col, newSize); // 3사분면 (왼쪽 아래)
        slice(row + newSize, col + newSize, newSize); // 4사분면 (오른쪽 아래)
        sb.append(')');

    }

    // 영역내 모든 숫자가 같은지 체크하는 함수
    static boolean check(int row, int col, int size) {
        int color = data[row][col]; // 영역 내 첫 색깔

        for (int i = row; i < row+size; i++) {
            for (int j = col; j < col+size; j++) {
                if (data[i][j] != color) {
                    return false; // 하나라도 색깔이 다르면 false
                }
            }
        }

        return true;
    }
}
