package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p5568 { // 백준 5568번 문제, 카드 놓기
    static int n, k;
    static int[] cards;
    static int[] pickedCards;
    static HashSet<String> result;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine()); // 카드 갯수
        k = Integer.parseInt(br.readLine()); // k개 사용

        cards = new int[n];
        pickedCards = new int[k];
        result = new HashSet<>();
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            cards[i] = Integer.parseInt(br.readLine());
        }
        picked(0);
        System.out.print(result.size());
    }


    static void picked(int depth) {
        StringBuilder sb = new StringBuilder();
        if (depth == k) {
            for (int j = 0; j < k; j++) {
                sb.append(pickedCards[j]);
            }
            result.add(String.valueOf(sb));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                pickedCards[depth] = cards[i];
                picked(depth + 1);
                visited[i] = false;
            }
        }
    }
}
