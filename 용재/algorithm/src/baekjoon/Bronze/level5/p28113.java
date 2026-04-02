package baekjoon.Bronze.level5;

import java.io.*;
import java.util.*;

public class p28113 { // 백준 28113번 문제, 정보섬의 대중교통
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 버스정류장 -> 숭실대 지하철
        int a = Integer.parseInt(st.nextToken()); // 숭실대 별관앞 정류소 -> 집 버스
        int b = Integer.parseInt(st.nextToken()); // 숭실대 입구역 -> 집 지하철

        // 지하철 열차 도착시간 = 지하철 역에 도착시간 -> 지하철 탑승 가능

        // 버스먼저 탑승 가능하면 Bus , 지하철 먼저면 Subway, 상관없으면 Anything

        if (a < b) {
            System.out.println("Bus");
        } else {
            if (a < n + (b-n)) {
                System.out.println("Bus");
            } else if (a > n + (b-n)) {
                System.out.println("Subway");
            } else {
                System.out.println("Anything");
            }
        }

    }
}
