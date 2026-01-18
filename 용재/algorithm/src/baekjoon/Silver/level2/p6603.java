package baekjoon.Silver.level2;

import java.util.*;
import java.io.*;

public class p6603 { // p6603번 문제, 로또
    static int k;
    static int[] num;
    static int[] result = new int[6];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());

            if (k == 0) {
                break;
            }

            num = new int[k];
            for (int i = 0; i < k; i++) {
                num[i] = Integer.parseInt(st.nextToken());
            }

            backtrack(0, 0);

            System.out.println(); // 테스트 케이스 사이 빈줄 추가
        }
    }

    static void backtrack(int start, int depth) {
        if (depth == 6) {
            for (int j = 0; j<6; j++) {
                System.out.print(result[j] +" ");
            }
            System.out.println();
            return;
        }
        // 뒤에있는 숫자만 고르기 위해 start 부터 시작
        for (int i = start; i < k; i++) {
            result[depth] = num[i];
            backtrack(i+1, depth+1);
        }

    }
}
