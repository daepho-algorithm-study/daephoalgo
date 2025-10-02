package baekjoon.Bronze.level1;

import java.util.Arrays;
import java.util.Scanner;

public class p10798 { // 백준 10798번, 세로읽기 (2차원 배열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] arr = new char[15][15];

        for (char[] row : arr) {
            Arrays.fill(row, '\0'); // '\0' 은 char 에서는 null로 존재하지만 (int) \0 시에 0으로 변환가능
        }

        for (int line = 0; line < 5; line++) {
            String word = sc.next();

            for (int i = 0; i < word.length(); i++) {
                arr[line][i] = word.charAt(i);
            }
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[j][i] != '\0') {
                    System.out.print(arr[j][i]);
                }
            }
        }

    }
}
