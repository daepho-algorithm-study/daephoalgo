package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p28279 { // 백준 28279번 문제, 덱2 (큐, 스택, 덱 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Deque<Integer> dq = new ArrayDeque<>();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int order = Integer.parseInt(st.nextToken());

            if (order == 1) {
                int x = Integer.parseInt(st.nextToken());
                dq.addFirst(x);
            } else if (order == 2) {
                int x = Integer.parseInt(st.nextToken());
                dq.addLast(x);
            } else if (order == 3) {
                if (dq.isEmpty()) {
                    sb.append(-1).append("\n");
                } else {
                    sb.append(dq.pollFirst()).append("\n");
                }
            } else if (order == 4) {
                if (dq.isEmpty()) {
                    sb.append(-1).append("\n");
                } else {
                    sb.append(dq.pollLast()).append("\n");
                }
            } else if (order == 5) {
                sb.append(dq.size()).append("\n");
            } else if (order == 6) {
                if (dq.isEmpty()) {
                    sb.append(1).append("\n");
                } else {
                    sb.append(0).append("\n");
                }
            } else if (order == 7) {
                if (dq.isEmpty()) {
                    sb.append(-1).append("\n");
                } else {
                    sb.append(dq.peekFirst()).append("\n");
                }
            } else if (order == 8) {
                if (dq.isEmpty()) {
                    sb.append(-1).append("\n");
                } else {
                    sb.append(dq.peekLast()).append("\n");
                }
            }
        }
        System.out.print(sb);
    }
}
