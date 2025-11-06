package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B2110 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] home = new int[n];

        int startHome = Integer.MAX_VALUE;
        int endHome = Integer.MIN_VALUE;

        for (int i = 0; i < home.length; i++) {
            home[i] = Integer.parseInt(br.readLine());
            if (home[i] < startHome) {
                startHome = home[i];
            } else if (home[i] > endHome) {
                endHome = home[i];
            }
        }

        // 집 위치를 순서에 맞게 정렬해야 올바른 카운트가 가능함
        Arrays.sort(home);

        // 이진 탐색
        // 왼쪽 범위 시작 = 1, 최소 거리
        // 오른쪽 범위 시작 = 최대거리, 마지막집 좌표 - 첫 집 좌표
        int left = 1;
        int right = endHome - startHome;

        int answer = 0;

        while (left <= right) {

            // 중간 거리 범위 설정하고 탐색 시작
            int mid = (left + right) / 2;

            int shareCnt = 1;

            int sharePos = startHome;


            // 현재 공유기 위치 + 중간 거리 시작 값이
            // 집 좌표와 일치하거나 집 좌표가 더 크면
            // 공유기 갯수를 + 1
            for (int i = 0; i < home.length; i++) {
                if (home[i] >= mid + sharePos) {
                    shareCnt++;
                    sharePos = home[i];
                }
            }

            // 여기 어딘가에 현재 공유기 포지션이 들어가서 갱신을 해줘야하는데 흠

            // 공유기 갯수가 많거나 같으면
            // 현재 거리포함 아래 범위는 다 해당되네?
            // 범위를 현재범위 1 올려서 다시 탐색
            // 일단 지금범위는 킵
            if (shareCnt >= c) {
                answer = mid;
                left = mid + 1;
            } else {
                // 갯수가 적으면
                // 이 범위 이상으로는 다 해당 안됨
                // 1줄이고 다시 탐색
                right = mid - 1;
            }
        }



        bw.write(String.valueOf(answer));

        bw.close();
        br.close();
    }


}
