package baekjoon.Silver.level2;

import java.io.*;
import java.util.*;

public class p11279 { // 백준 11279번 문제, 최대 힙
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> q = new PriorityQueue<Integer>(n, Collections.reverseOrder()); // n의 크기를 가진 우선순위 큐를 내림차순으로 정렬

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());

            if (num != 0) {
                q.add(num);
            } else {
                if (q.isEmpty()) {
                    System.out.println(0);
                } else {
                    System.out.println(q.poll());
                }
            }
        }


    }
}
