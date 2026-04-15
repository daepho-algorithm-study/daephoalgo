package baekjoon.Bronze.level5;

import java.io.*;

public class p15727 { // 백준 15727번 문제, 조별과제를 하려는데 조장이 사라졌다
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int L = Integer.parseInt(br.readLine());

        int t = 0;
        int range = 5;
        int cnt = 0;
        while (t != L) {
            if (L > t) {
                cnt++;
                t += range;
            } else if (L < t) {
                cnt--;
                t -= range;
                range -= 1;
            }
        }

        System.out.println(cnt);
    }
}
