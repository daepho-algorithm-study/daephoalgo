package CodeTree.Trail_0.Chapter_9.Lesson_1;

import java.util.Scanner;

public class C1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        for (int i = n; i > 0; i--) {
            for (int j = m; j > 0; j--) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }
    }
}
