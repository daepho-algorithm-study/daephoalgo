package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p2164 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            q.add(i);
        }
        for (int j = 0; j < N-1; j++) {
            q.poll();
            q.add(q.poll());
        }
        System.out.println(q.poll());
    }
}
