package CodeTree.Trail_0.Chapter_9.Lesson_4;

import java.util.Scanner;

public class C2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int start = input.nextInt();
        int end = input.nextInt();

        int answer = 0;

        for (int i = start; i <= end; i++) {
            int check = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    check++;
                }
            }
            if (check == 3) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}
