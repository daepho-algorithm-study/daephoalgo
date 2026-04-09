package baekjoon.Bronze.level4;

import java.io.*;

public class p28431 { // 백준 28431번 문제, 양말 짝 맞추기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[5];
        int[] arr2 = new int[10]; // 모든 숫자는 0이상 9이하

        for (int i = 0; i < 5; i++) {
            int n = Integer.parseInt(br.readLine());
            arr[i] = n;
            if (arr2[n] == 0) {
                arr2[n] = 1;
            } else {
                arr2[n] = 0;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (arr2[i] != 0) {
                System.out.println(i);
            }
        }

    }
}
