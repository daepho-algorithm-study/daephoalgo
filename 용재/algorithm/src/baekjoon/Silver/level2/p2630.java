package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p2630 { // 백준 2630번 문제, 색종이 만들기
    static int[][] paper;
    static int white = 0; // 하얀색 색종이 (0) 개수
    static int blue = 0;  // 파란색 색종이 (1) 개수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        paper = new int[n][n];

        // 색종이 상태 입력 받기
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 전체 종이에 대해 분할 정복 시작 (시작점 0,0 / 크기 n)
        slice(0, 0, n);

        // 결과 출력
        System.out.println(white);
        System.out.println(blue);
    }

    // 색종이를 자르는 재귀 함수
    public static void slice(int row, int col, int size) {

        // 1. 현재 영역이 모두 같은 색인지 확인
        if (colorCheck(row, col, size)) {
            if (paper[row][col] == 0) {
                white++;
            } else {
                blue++;
            }
            return; // 같은 색이면 카운트 후 해당 재귀 종료
        }

        // 2. 다른 색이 섞여 있다면 크기를 절반으로 줄여서 4등분
        int newSize = size / 2;

        slice(row, col, newSize);                       // 1사분면 (왼쪽 위)
        slice(row, col + newSize, newSize);             // 2사분면 (오른쪽 위)
        slice(row + newSize, col, newSize);             // 3사분면 (왼쪽 아래)
        slice(row + newSize, col + newSize, newSize);   // 4사분면 (오른쪽 아래)
    }

    // 지정된 영역 내 색상이 모두 같은지 체크하는 함수
    public static boolean colorCheck(int row, int col, int size) {
        int color = paper[row][col]; // 해당 영역의 첫 번째 칸 색상 기준

        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                // 하나라도 다르면 섞여 있는 것이므로 false 리턴
                if (paper[i][j] != color) {
                    return false;
                }
            }
        }
        // 모두 같은 색이면 true 리턴
        return true;
    }
}