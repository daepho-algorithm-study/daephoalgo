package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p1072 { // 백준 1072번 문제, 게임
    static long x, y;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Long.parseLong(st.nextToken());
        y = Long.parseLong(st.nextToken());

        System.out.println(binary(x, y));

    }

    static long binary(Long x, Long y) {
        long start = 1;
        long end = 1_000_000_000;
        long ratio = ((y * 100 / x));
        long result = -1;

        if (ratio >= 99) {
            return result;
        }
        while (start <= end) {
            long mid = (start + end) / 2;
            long newRatio = ((y + mid) * 100) / (x + mid);

            if (ratio == newRatio) {
                start = mid + 1;
            } else {
                end = mid - 1;
                result = mid;
            }

        }

        return result;
    }
}
