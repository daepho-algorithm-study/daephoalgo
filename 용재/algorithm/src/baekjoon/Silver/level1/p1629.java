package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p1629 { // 백준 1629번 문제, 곱셈
    static long a, b, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Long.parseLong(st.nextToken()); // 초기숫자 a
        b = Long.parseLong(st.nextToken()); // A를 B번 곱할 숫자
        c = Long.parseLong(st.nextToken()); // 마지막에 c로 나눌 숫자

        System.out.println(divide(b));
    }

    // 반씩 쪼개가며 계산하는 재귀함수
    static long divide(long n) {
        if (n == 1) { // 지수가 1이면 더 못쪼개니까 나머지 리턴
            return a % c;
        }

        // 반으로 쪼개서 한번만 계산
        // ex. 11이면 divide(5)가 호출되고 그 결과가 half에 담김
        long half = divide(n / 2);

        // 구한 반쪽을 두 번 곱해서 합치기
        // -> 곱하는 순간 long 범위를 넘을 수 있으니 바로 %c 연산
        long result = (half * half) % c;

        // 지수가 홀수였을 경우의 처리
        if (n % 2 != 0) {
            return (result * (a % c)) % c;
        }

        // 지수가 짝수면 그대로 result 리턴
        return result;
    }

}
