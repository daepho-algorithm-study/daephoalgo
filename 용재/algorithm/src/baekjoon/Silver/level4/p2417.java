package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;
public class p2417 { // 백준 2417번 문제, 정수 제곱근
    public static long N;
    public static long answer = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());

        binarySearch();
        System.out.println(answer);
    }

    public static void binarySearch() {
        long start = 0;
        long end = N;

        while(start <= end) {
            long middle = ( start + end ) / 2;

            // mid*mid 하면 overflow 가능성있어서 Math.pow써야함
            if( Math.pow(middle, 2) >= N ) {
                answer = middle;
                end = middle - 1;
            } else  {
                start = middle + 1;
            }
        }
    }
}
