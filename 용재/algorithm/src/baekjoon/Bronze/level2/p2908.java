package baekjoon.Bronze.level2;

import java.util.Scanner;

public class p2908 { // 2908번 상수(문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();

        sc.close();

        // 결과 값이 String이기 때문에 String으로 선언하고 StringBuilder에 a|b를 넣은다음 뒤집고 String으로 변환
        String sbA = new StringBuilder(a).reverse().toString();
        String sbB = new StringBuilder(b).reverse().toString();

        // 이후 parseInt를 통해 정수형으로 변환
        int resultA = Integer.parseInt(sbA);
        int resultB = Integer.parseInt(sbB);

        System.out.println(resultA > resultB ? resultA : resultB);

    }
}
