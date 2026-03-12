package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p2075 { // 백준 2075번 문제, N번째 큰 수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());


        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                q.add(Integer.parseInt(st.nextToken()));
            }
        }

        while (n-- > 0) {

            if (n == 0) {
                bw.write(String.valueOf(q.poll()));
            }
            else {
                q.poll();
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }

}
