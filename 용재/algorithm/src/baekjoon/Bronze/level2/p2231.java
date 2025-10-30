package baekjoon.Bronze.level2;

import java.io.*;
import java.util.*;

public class p2231 { // 백준 2231번, 분해합 (브루트 포스)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int min = n; // 어차피 최소값은 n보다 작기때문

        for (int i = n; i > 0; i--) {
            int sum = i;
            int num = i;
            while (num != 0) {
                sum += num % 10; // 10을 몫나누기 하면 가장 끝 자리만 얻을 수 있음
                num = num / 10; // 이후 10 나눠서 끝자리만 제거
            }
            if (sum == n) {
                min = i;
            }
        }

        System.out.println(min == n ? 0 : min); // min == n 이면 생성자가 없다는것이기에 0 출력

    }
}
