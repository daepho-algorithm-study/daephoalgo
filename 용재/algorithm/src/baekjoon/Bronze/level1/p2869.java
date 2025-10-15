package baekjoon.Bronze.level1;

import java.io.*;
import java.util.*;

public class p2869 {
    public static void main(String[] args) throws IOException { // 백준 2869번 문제, 달팽이는 올라가고 싶다 (수학 1)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        StringTokenizer st = new StringTokenizer(line);

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        // ( v - a ) : 마지막 날을 제외하고 올라가야 할 높이
        // ( a - b ) : 하루에 순수하게 올라가는 높이
        int day = (v - a) / (a - b);

        if ((v - a) % (a - b) != 0) { // 나머지가 있으면 하루 더 올라가야한다는뜻
            day++;
        }
        System.out.print(day + 1);

//        int position = 0;
//        int day = 0;
//
//        while (position < v) {
//            day++;
//            position += a;
//            if (position >= v) {
//                break;
//            }
//            position -= b;
//        }
//        System.out.print(day);
    }
}
