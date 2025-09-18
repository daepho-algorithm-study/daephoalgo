package CodeTree.Trail_0.Chapter_10.Lesson_2;

import java.util.Scanner;

public class C2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int[][] arr = new int[6][3];

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = input.nextInt();
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j] * arr[i+3][j] + " ");
            }
            System.out.println();
        }

    }
}
