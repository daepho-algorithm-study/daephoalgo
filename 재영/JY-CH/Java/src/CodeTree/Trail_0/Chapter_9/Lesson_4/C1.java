package CodeTree.Trail_0.Chapter_9.Lesson_4;

import java.util.Scanner;

public class C1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for (int i = 0; i < n; i++) {

            int a = input.nextInt();
            int b = input.nextInt();
            int answer = 0;

            for (int j = a; j <= b; j++) {

                if (j % 2 == 0) {
                    answer += j;
                }

            }
            System.out.println(answer);
        }
    }
}
