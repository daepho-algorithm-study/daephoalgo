package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p1780 {
    static int n;
    static int[][] arr;
    static int minus = 0;
    static int zero = 0;
    static int plus = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];

        for (int i = 0; i < n; i++) { // 배열 초기화
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        slice(0,0,n);
        System.out.println(minus);
        System.out.println(zero);
        System.out.println(plus);
    }


    public static void slice(int col, int row, int size) {

        int number = arr[col][row];

        if (check(col, row, size)) {
            if (number == -1) {
                minus++;
            } else if (number == 0) {
                zero++;
            } else {
                plus++;
            }
            return;
        }

        int newSize = size / 3;

        slice(col, row, newSize); // 좌상단
        slice(col,row+newSize,newSize); // 중간상단
        slice(col,row+(newSize*2),newSize); // 우상단
        slice(col+newSize,row,newSize); // 좌중간
        slice(col+newSize,row+newSize,newSize); // 정중앙
        slice(col+newSize,row+(newSize*2),newSize); // 우중간
        slice(col+(newSize*2),row,newSize); // 좌하단
        slice(col+(newSize*2),row+newSize,newSize); //중간하단
        slice(col+(newSize*2),row+(newSize*2),newSize); // 우하단
    }

    public static boolean check(int col, int row, int size) {
        int start = arr[col][row]; // 시작 숫자

        for (int i = col; i < col+size; i++) {
            for (int j = row; j < row+size; j++) {
                if (arr[i][j] != start) {
                    return false; // 하나라도 다르다면 false
                }
            }
        }

        // for문 전부 통과하면 모든 숫자가 동일하니 true;
        return true;
    }
}
