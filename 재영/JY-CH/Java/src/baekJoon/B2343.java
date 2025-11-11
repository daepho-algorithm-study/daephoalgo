package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B2343 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        int sum = 0;
        int max = Integer.MIN_VALUE;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sum += arr[i];
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // 블루레이의 최소 길이는
        // 입력 받은 값중 가장 큰값, 갯수 n 개
        // 최대 길이는 전체합, 갯수 1개
        int left =  max;
        int right = sum;

        int answer = 0;


        // 길이를 이용한 탐색
        while (left <= right) {

            int mid = (left + right) / 2;

            int partialSum = 0;

            // 당연히 최소 1개는 있어야한다.
            int video = 1;

            for (int i = 0; i < arr.length; i++) {
                
                // 값이 초과되면
                // 비디오 + 1, 부분합은 초기화 및 재설정
                if (partialSum + arr[i] > mid) {
                    video++;
                    partialSum = arr[i];
                } else {
                    partialSum += arr[i];
                }


            }

            // 비디오 개수가 많다?
            // 길이가 작아서 갯수 보다 많은 비디오를 필요로 했다.
            // 비디오의 길이를 늘려야한다. 왼쪽 범위를 줄이자.
            if (video > m) {
                left = mid + 1;
            } else {
                // 작거나 같으면
                // 일단 조건은 만족했어도 더 되는지 찾아보자
                // 값 킵하고, 오른쪽 범위를 줄여보자
                answer = mid;
                right = mid - 1;
            }
        }



        bw.write(String.valueOf(answer));

        br.close();
        bw.close();
    }
}
