package baekjoon.Bronze.level4;

import java.io.*;
import java.util.*;

public class p15080 { // 백준 15080번 문제, Every Second Counts
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int hour = Integer.parseInt(st.nextToken());
        String colon = st.nextToken();
        int minutes = Integer.parseInt(st.nextToken());
        colon = st.nextToken();
        int seconds = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int lateHour = Integer.parseInt(st.nextToken());
        colon = st.nextToken();
        int lateMinutes = Integer.parseInt(st.nextToken());
        colon = st.nextToken();
        int lateSeconds = Integer.parseInt(st.nextToken());

        int before = hour * 3600 + minutes * 60 + seconds;
        int after = lateHour * 3600 + lateMinutes * 60 + lateSeconds;

        int diff = after - before;
        if (diff >= 0) {
            System.out.print(diff);
        } else {
            System.out.println(24*3600+diff);
        }

    }
}

