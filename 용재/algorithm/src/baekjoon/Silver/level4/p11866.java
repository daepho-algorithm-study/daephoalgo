package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

public class p11866 { // 백준 11866번 문제, 요세푸스 문제 0 (스택, 큐, 덱1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            q.add(i);
        }
        StringBuilder sb = new StringBuilder();
        sb.append("<");
        while (!q.isEmpty()) {
            for (int j = 0; j < K - 1; j++) {
                q.add(q.poll());
            }
            if (q.size() == 1) {
                sb.append(q.poll()).append(">");
            } else {
                sb.append(q.poll()).append(", ");
            }

        }
        System.out.println(sb);
    }
}
