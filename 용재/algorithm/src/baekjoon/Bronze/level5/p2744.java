package baekjoon.Bronze.level5;

import java.io.*;

public class p2744 { // 백준 2744번 문제, 대소문자 바꾸기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String words = br.readLine();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < words.length(); i++) {
            char word = words.charAt(i);
            if (Character.isUpperCase(word)) {
                sb.append(Character.toLowerCase(word));
            } else {
                sb.append(Character.toUpperCase(word));
            }
        }
        System.out.print(sb);
    }
}
