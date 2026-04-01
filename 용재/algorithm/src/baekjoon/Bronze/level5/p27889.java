package baekjoon.Bronze.level5;

import java.io.*;

public class p27889 { // 백준 27889번 문제, 특별한 학교 이름
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String word = br.readLine();

        if (word.equals("NLCS")) {
            System.out.println("North London Collegiate School");
        } else if (word.equals("BHA")) {
            System.out.println("Branksome Hall Asia");
        } else if (word.equals("KIS")) {
            System.out.println("Korea International School");
        } else {
            System.out.println("St. Johnsbury Academy");
        }
    }
}
