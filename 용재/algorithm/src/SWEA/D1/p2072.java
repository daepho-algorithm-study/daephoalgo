package SWEA.D1;

import java.io.*;
import java.util.*;

public class p2072 { // SWEA 2072번 문제, 홀수만 더하기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine()); // 테스트 케이스

        for (int tc = 0; tc < t; tc++) {
            int result = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 10; i++) {
                int num = Integer.parseInt(st.nextToken());
                if (num % 2 != 0) {
                    result += num;
                }
            }
            StringBuilder sb = new StringBuilder();
            sb.append("#").append(tc+1).append(" ").append(result);
            System.out.println(sb);

        }


    }
}
