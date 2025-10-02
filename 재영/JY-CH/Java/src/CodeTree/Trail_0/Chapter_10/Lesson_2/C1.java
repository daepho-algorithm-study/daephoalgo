package CodeTree.Trail_0.Chapter_10.Lesson_2;

import java.util.Scanner;

public class C1 {
        public static void main(String[] args) {


            Scanner input = new Scanner(System.in);

            int[][] arr = new int[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = (input.nextInt()) * 3;
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();
            }


        }
}
