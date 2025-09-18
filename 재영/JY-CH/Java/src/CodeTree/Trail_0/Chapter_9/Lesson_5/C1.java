package CodeTree.Trail_0.Chapter_9.Lesson_5;

import java.util.Scanner;

public class C1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        int sum = 0;

        for (int i = 1; i <= n; i++) {

            sum+=i;

            for (int j = 1; j <= i; j++) {
                System.out.print((sum - i + j) + " ");
            }

            System.out.println();
        }
    }
}
