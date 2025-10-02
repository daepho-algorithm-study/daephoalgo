package CodeTree.Trail_0.Chapter_9.Lesson_2;

import java.util.Scanner;

public class C2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for (int i = 1; i <= n; i++) {
            int starCount = 2 * i - 1;
            for (int j = 0; j < starCount; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
