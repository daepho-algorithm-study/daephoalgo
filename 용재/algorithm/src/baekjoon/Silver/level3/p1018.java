package baekjoon.Silver.level3;

import java.util.*;
import java.io.*;

public class p1018 { // 백준 1018번,  체스판 다시 칠하기(브루트 포스)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
        int minCnt = 999999999;
        char start;
        for (int w = 0; w < 2; w++) {
            if (w % 2 == 0) {
                start = 'B';
            } else {
                start = 'W';
            }
            for (int i = 0; i < n - 7; i++) {
                for (int k = 0; k < m - 7; k++) {
                    int cnt = 0;
                    for (int j = i; j < i + 8; j++) { // 세로로 8개씩 순회
                        for (int q = k; q < k + 8; q++) { // 가로로 8개씩 순회
                            if (start == 'B') {
                                if ((j - i) % 2 == 0 && (q - k) % 2 == 0) { // 짝수번째라인의 짝수번째 문자
                                    if (arr[j].charAt(q) == 'W') {
                                        cnt++;
                                    }
                                } else if ((j - i) % 2 == 0 && (q - k) % 2 == 1) { // 짝수번째 라인의 홀수번째 문자
                                    if (arr[j].charAt(q) == 'B') {
                                        cnt++;
                                    }
                                } else if ((j - i) % 2 == 1 && (q - k) % 2 == 0) {// 홀수번째 라인의 짝수번째 문자
                                    if (arr[j].charAt(q) == 'B') {
                                        cnt++;
                                    }
                                } else { // 홀수번째 라인의 홀수번째 문자
                                    if (arr[j].charAt(q) == 'W') {
                                        cnt++;
                                    }
                                }
                            } else { // 시작이 W일 때
                                if ((j - i) % 2 == 0 && (q - k) % 2 == 0) { // 짝수번째라인의 짝수번째 문자
                                    if (arr[j].charAt(q) == 'B') {
                                        cnt++;
                                    }
                                } else if ((j - i) % 2 == 0 && (q - k) % 2 == 1) { // 짝수번째 라인의 홀수번째 문자
                                    if (arr[j].charAt(q) == 'W') {
                                        cnt++;
                                    }
                                } else if ((j - i) % 2 == 1 && (q - k) % 2 == 0) {// 홀수번째 라인의 짝수번째 문자
                                    if (arr[j].charAt(q) == 'W') {
                                        cnt++;
                                    }
                                } else { // 홀수번째 라인의 홀수번째 문자
                                    if (arr[j].charAt(q) == 'B') {
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                    if (cnt < minCnt) {
                        minCnt = cnt;
                    }
                }
            }
        }
        System.out.println(minCnt);
    }
}