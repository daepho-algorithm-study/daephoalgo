package baekjoon.Bronze.level4;

import java.io.*;
import java.util.*;

public class p10101 { // 백준 10101번, 삼각형 외우기 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        if (a + b + c == 180) {

            if (a == b && a == c) {
                System.out.println("Equilateral");
            }
            if (a == b && a != c) {
                System.out.println("Isosceles");
            } else if (a != b && a == c) {
                System.out.println("Isosceles");
            } else if (a != b && b == c) {
                System.out.println("Isosceles");
            }
            if (a != b && a != c && b != c) {
                System.out.println("Scalene");
            }
        } else {
            System.out.println("Error");
        }
    }
}
