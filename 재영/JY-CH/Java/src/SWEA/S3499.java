package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S3499 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            int range = Integer.parseInt(br.readLine());

            // 이번 배열은 문자열 배열이다.
            String[] arr = new String[range];

            // 문자열 배열 입력 받고 저장
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = String.valueOf(st.nextToken());
            }

            // 홀수 짝수에 대한 구분을 해야됨
            // 홀수면 1 2 3 4 5 가 1 4 2 5 3
            // 짝수면 1 4 2 5 3 6
            // 2로 나눈 몫을 이용하기로함
            // 배열 길이 2로 나눈 나머지로 판 별
            // 0이다 == 짝수다
            bw.write("#" + test + " ");
            if ((arr. length % 2) == 0) {
                for (int i = 0; i < (arr.length / 2); i++) {
                    bw.write(arr[i] + " ");
                    bw.write(arr[(arr.length / 2) + i] + " ");
                }
            } else {
                bw.write(arr[0] + " ");
                for (int i = 0; i < (arr.length / 2); i++) {
                    bw.write(arr[((arr.length / 2) + i) + 1] + " ");
                    bw.write(arr[i + 1] + " ");
                }
            }

            bw.newLine();


        }



        bw.close();
        br.close();
    }


}
