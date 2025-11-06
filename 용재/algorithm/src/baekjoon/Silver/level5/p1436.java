package baekjoon.Silver.level5;

import java.util.*;
import java.io.*;

public class p1436 { // 백준 1436번 문제, 영화감독 숌 (브루트 포스)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        // 666, 1666, 2666, 3666, ...
        // 2 -> 1666 , 187 -> 66666
        int total =0;
        int ans =0;
        for (int i = 0; i < 10000 * 666; i++) {
            String num = String.valueOf(i);
            for (int j = 1; j < num.length()-1; j++) {
                if (num.charAt(j-1)=='6'&&num.charAt(j)=='6'&&num.charAt(j+1)=='6') {
                    total++;
                    break;
                }
            }
            if (total == n) {
                ans = i;
                break;
            }
        }

        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
}
