package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p2529 { // 백준 2429번 문제, 부등호
    static int k;
    static String[] arr;
    static List<String> result = new ArrayList<>();
    static boolean[] visited = new boolean[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        k = Integer.parseInt(br.readLine());
        arr = new String[k];


        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < k; i++) {
            arr[i] = st.nextToken();
        }
        cal(0, "");

        // 문자열로 담았으니 정렬하면 숫자 크기순으로 정렬
        Collections.sort(result);

        // 최댓값
        System.out.println(result.get(result.size()-1));

        // 최소값
        System.out.println(result.get(0));
    }

    static void cal(int depth, String numStr) {
        if (depth == k + 1) {
            result.add(numStr);
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                // 깊이가 0이면 비교할 게 없으니 통과 (이거 안하면 outOfRange 오류 발생
                // 깊이 0 아니면 직전 숫자와 현재 숫자 비교 (numStr의 마지막 글자 - '0' 하면 숫자로 나옴)
                if (depth == 0 || check(numStr.charAt(depth - 1) - '0', i, arr[depth - 1])) {
                    visited[i] = true;
                    cal(depth + 1, numStr + i); // 문자열 이어붙여서 재귀
                    visited[i] = false;
                }
            }
        }
    }

    // 부등호 조건 체크 함수
    static boolean check(int prev, int now, String sign) {
        if (sign.equals(">")) {
            return prev > now;
        } else {
            return prev < now;
        }
    }
}



