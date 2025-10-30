package codingTest.greedyAlgorithm;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CT_3_2 {
    public static void main(String[] args) throws IOException {

        // 큰 수의 법칙
        // 다양한 수로 이루어진 배열이 있을때 주어진 수들을 m번 더해 가장 큰수 만들기
        // 단, 특정 인덱스에 해당하는 수가 연속해서 k번 초과해 더 해질 수 없다.

        // 2, 4, 5, 4, 6
        // m = 8, k = 3
        // 6 6 6 5 6 6 6 5 = 46

        // 서로 다른 인덱스에 해당하는 수가 같을 경우는 다른 수로 본다!
        // 3 4 3 4 3
        // m = 7 , k = 2
        // 4 4 4 4 4 4 4 = 28

        // 입력 조건
        // 첫째 줄에 N(2 <= N <= 1000), M( 1 <= M <= 10,000), K(1 <= K <= 10,000)의 자연수가 주어지며, 각 자연수는 공백으로 구분한다.
        // 둘째 줄에 N개의 자연수가 주어진다. 각 자연수는 공백으로 구분한다. 단, 각각의 자연수는 1 이상 10,000이하의 수로 주어진다.
        // 입력으로 주어지는 K는 항상 M보다 작거나 같다.
        //
        // 출력 조건
        // 첫째 줄에 동빈이의 큰 수의 법칙에 따라 더해진 답을 출력한다.

        // 입력 예시
        // 5 8 3
        // 2 4 5 4 6

        // 출력 예시
        // 46


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int maxNum = arr[n - 1];
        int secondMaxNum = arr[n - 2];

        // 한번 도는? 횟수
        int pattern = k + 1;
        // 실질적으로 제일 높은값이 더해지는 횟수
        int count = (m / pattern) * k + (m % pattern);
        
        // 실질적으로 높은자리 수가 더해지는 횟수
        // 를 제외하고 두번째 높은수가 더해지는 횟수
        int result = count * maxNum + (m - count) * secondMaxNum;

        bw.write(result + "\n");



        bw.close();
        br.close();
    }


}
