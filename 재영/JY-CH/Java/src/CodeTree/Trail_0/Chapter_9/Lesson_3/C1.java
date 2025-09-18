package CodeTree.Trail_0.Chapter_9.Lesson_3;

import java.util.Scanner;

public class C1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(i + " * " + j + " = " + (i * j) + "");
                if (j != n) {
                    System.out.print(", ");
                }
            }
            System.out.println();
        }
    }
}
