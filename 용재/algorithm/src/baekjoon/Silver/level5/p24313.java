package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p24313 { // 백준 24313번 문제, 알고리즘 수업 - 점근적 표기 1 (시간 복잡도)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a1 = Integer.parseInt(st.nextToken());
        int a0 = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int c = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int n0 = Integer.parseInt(st.nextToken());

        if ((a1 * n0 + a0 <= c * n0) && (a1 <= c)) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }

    }
}
