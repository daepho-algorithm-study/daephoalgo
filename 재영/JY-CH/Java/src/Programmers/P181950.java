package Programmers;

import java.util.Scanner;

public class P181950 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        for (int repeat = 0; repeat < n; repeat++) {
            System.out.print(str);
        }
    }
}
