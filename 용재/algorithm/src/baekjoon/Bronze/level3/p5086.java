package baekjoon.Bronze.level3;

import java.io.*;
import java.util.*;

public class p5086 { // 백준 5086번 문제, 배수와 약수 (약수, 배수와 소수 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0) {
                br.close();
                break;
            }
            if (a >= b) {
                if (a % b == 0) {
                    System.out.println("multiple");
                }
                else {
                    System.out.println("neither");
                }
            } else {
                if (b%a == 0) {
                    System.out.println("factor");
                } else {
                    System.out.println("neither");
                }
            }
        }
    }
}
