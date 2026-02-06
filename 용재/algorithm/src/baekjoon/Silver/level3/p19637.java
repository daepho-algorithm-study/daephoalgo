package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p19637 { // 백준 19637번 문제, IF문 좀 대신 써줘
    static String[] title;
    static int[] power;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 칭호의 개수
        int m = Integer.parseInt(st.nextToken()); // 캐릭터의 개수

        title = new String[n];
        power = new int[n];

        // 칭호와 기준값 입력 받기
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            title[i] = st.nextToken();
            power[i] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();

        // 캐릭터 하나씩 입력받으면서 바로바로 이분 탐색 수행
        for (int j = 0; j < m; j++) {
            int characterPower = Integer.parseInt(br.readLine());

            // 이 캐릭터의 전투력(characterPower)이 몇 번째 칭호에 해당하는지 찾기
            int index = binarySearch(characterPower);
            sb.append(title[index]).append("\n");
        }

        System.out.print(sb);
    }

    // 이분 탐색: power 배열에서 target보다 크거나 같은 첫 번째 값 찾기 (Lower Bound)
    static int binarySearch(int target) {
        int start = 0;
        int end = power.length - 1;
        int resultIdx = 0;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (power[mid] >= target) {
                // 내 전투력을 커버할 수 있는 칭호임!
                resultIdx = mid;  // 일단 정답 후보로 기록
                end = mid - 1;    // "혹시 더 낮은 기준의 칭호도 가능한가?" 확인하러 왼쪽으로 이동
            } else {
                // 이 칭호 기준보다 내 전투력이 더 큼 -> 더 센 칭호를 봐야 함
                start = mid + 1;  // 오른쪽으로 이동
            }
        }
        return resultIdx; // 찾은 인덱스 반환
    }
}