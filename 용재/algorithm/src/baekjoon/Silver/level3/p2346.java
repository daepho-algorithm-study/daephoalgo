package baekjoon.Silver.level3;

import java.util.*;
import java.io.*;

public class p2346 { // 백준 2346번 문제, 풍선 터뜨리기 (큐,스택,덱 2)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Deque<int[]> q = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        sb.append("1 ");
        int in = arr[0];

        for (int i = 1; i < n; i++) {
            q.add(new int[]{(i + 1), arr[i]}); // {풍선 idx, 내용}
        }

        while (!q.isEmpty()) {
            // 양수인 경우
            if (in > 0) {
                // 순서 뒤로 돌리기
                for (int i = 1; i < in; i++) {
                    q.add(q.poll()); // 앞에서빼서 뒤로넣기
                }

                int[] nxt = q.poll();
                in = nxt[1];
                sb.append(nxt[0] + " ");
            }
            // 음수인 경우
            else {
                for (int i = 1; i < -in; i++) {
                    q.addFirst(q.pollLast()); // 뒤에서 빼서 앞으로 넣기
                }

                int[] nxt = q.pollLast();
                in = nxt[1];
                sb.append(nxt[0] + " ");
            }
        }

        System.out.println(sb);

    }
}
