package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

public class p2839 { // 백준 2839번 문제, 설탕배달 (브루트 포스)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        while (n > 0) {

            if (n % 5 == 0) {
                ans += n / 5;
                break;
            }

            n = n - 3;
            ans++;
        }


        if (n<0) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }

    }
}
