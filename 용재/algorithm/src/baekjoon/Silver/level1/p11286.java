package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p11286 { // 백준 11286번 문제, 절댓값 힙
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> q = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (Math.abs(o1) == Math.abs(o2)) {

                    // o1이 o2보다 크면 양수(자리 바꿈), 아니면 음수(그대로)
                    return o1 - o2;
                } else {
                    return Math.abs(o1) - Math.abs(o2);
                }
            }
        });

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());

            if (num != 0) {
                q.add(num);
            } else {
                if (q.isEmpty()) {
                    bw.write(0 + "\n");
                } else {
                    bw.write(q.poll() + "\n");
                }
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
