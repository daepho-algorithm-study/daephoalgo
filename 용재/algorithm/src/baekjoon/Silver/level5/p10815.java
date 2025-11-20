package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p10815 { // 백준 10815번 문제, 숫자카드 (집합과 맵)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()); // n을 받기위한 토크나이저

        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[20_000_001];

        st = new StringTokenizer(br.readLine()); // 상근이의 숫자 카드 받기 위한 토크나이저
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            x += 10_000_000;
            arr[x] += 1;
        }

        st = new StringTokenizer(br.readLine()); // m을 받기위한 토크나이저
        int m = Integer.parseInt(st.nextToken());
        int[] arr2 = new int[m];
        st = new StringTokenizer(br.readLine()); // 비교해야할 숫자카드를 받기위한 토크나이저
        for (int j = 0; j < m; j++) {
            int y = Integer.parseInt(st.nextToken());
            arr2[j] = y;
            y += 10_000_000;
            arr[y] += 1;
        }

        for (int s = 0; s < arr2.length; s++) {
            if (arr[arr2[s]+10_000_000] == 1) {
                System.out.print("0 ");
            } else if (arr[arr2[s]+10_000_000] == 2){
                System.out.print("1 ");
            }
        }
    }
}
