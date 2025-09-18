package CodeTree.Trail_0.Chapter_10.Lesson_2;

import java.util.Scanner;

public class C3 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        int[][] inputArr = new int[n*2][m];

        for (int row = 0; row < (n * 2); row++) {
            for (int col = 0; col < m; col++) {
                inputArr[row][col] = input.nextInt();
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (inputArr[row][col] == inputArr[row + n][col]) {
                    System.out.print(0 + " ");
                } else {
                    System.out.print(1 + " ");
                }
            }
            System.out.println();
        }

    }
}
