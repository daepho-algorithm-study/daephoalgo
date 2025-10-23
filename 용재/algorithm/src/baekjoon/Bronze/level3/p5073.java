package baekjoon.Bronze.level3;

import java.util.*;
import java.io.*;

public class p5073 { // 백준 5073번, 삼각형과 세 변 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (a == 0 && b == 0 && c == 0) {
                break;
            }
            if (a>=b && a>=c) {
                if (a>=b+c) {
                    System.out.println("Invalid");
                    continue;
                }
            }
            if (b>=a && b>=c) {
                if (b>=a+c) {
                    System.out.println("Invalid");
                    continue;
                }
            }
            if (c>=a && c>=b) {
                if (c>=a+b) {
                    System.out.println("Invalid");
                    continue;
                }
            }

            if (a == b && b == c) {
                System.out.println("Equilateral");
            } else if (a == b) {
                System.out.println("Isosceles");
            } else if (b == c) {
                System.out.println("Isosceles");
            } else if (a == c) {
                System.out.println("Isosceles");
            } else {
                System.out.println("Scalene");
            }
        }
        br.close();
    }
}
