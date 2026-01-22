package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p2961 { // 백준 2961번 문제, 도영이가 만든 맛있는 음식
    static int n, s, b;
    static int minDiff = Integer.MAX_VALUE; // 요리 맛의 차이가 최소
    static int[][] food;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine()); // 재료의 개수 n
        food = new int[n][2];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken()); // 신맛 s
            b = Integer.parseInt(st.nextToken()); // 쓴맛 b

            food[i] = new int[]{s, b};
        }
        cook(0, 1, 0, 0);
        System.out.println(minDiff);
    }

    static void cook(int depth, int sour, int bitter, int diff) {

        if (depth == n) {
            if (sour != 1 && bitter != 0) {
                minDiff = Math.min(minDiff, diff);
            }
            return;
        }
        // 현재 원소 선택하는 경우
        cook(depth + 1, sour * food[depth][0], bitter + food[depth][1], Math.abs((sour * food[depth][0]) - (bitter + food[depth][1])));
        // 선택하지 않는 경우
        cook(depth + 1, sour, bitter, Math.abs((sour - bitter)));


    }
}
