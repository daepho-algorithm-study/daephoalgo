package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p11723 { // 백준 11723번 문제, 집합
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();

        HashSet<Integer> s = new HashSet<>();
        int n = Integer.parseInt(br.readLine()); // 명령 수 n

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String order = st.nextToken();
            if (order.equals("all") || order.equals("empty")) {
                if (order.equals("all")) {
                    for (int j = 1; j < 21; j++) {
                        s.add(j);
                    }
                } else {
                    s.clear();
                }
            } else {
                int num = Integer.parseInt(st.nextToken());
                if (order.equals("add")) {
                    s.add(num);
                } else if (order.equals("remove")) {
                    s.remove(num);
                } else if (order.equals("check")) {
                    if (s.contains(num)) {
                        sb.append(1).append("\n");
                    } else {
                        sb.append(0).append("\n");
                    }
                } else {
                    if (s.contains(num)) {
                        s.remove(num);
                    } else {
                        s.add(num);
                    }
                }
            }
        }
        System.out.print(sb);

    }
}
