package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class B2512 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 예산
        // 요구 예산 합계액이 m 보다 작으면 전부 지급하고 최대치 출력
        // m보다 크다면 예산 내에서 최대한 줄 수 있는 상한액을 배정하여 준다.
        // 상한액 보다 작으면 해당 예산을, 크다면 상한액만큼

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];

        int maxBudget = Integer.MIN_VALUE;

        int totalBudget = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            totalBudget += arr[i];
            if (arr[i] > maxBudget) {
                maxBudget = arr[i];
            }
        }

        int m = Integer.parseInt(br.readLine());

        // 예산 요청 합계액이 예산 총액과 같거나 작으면
        // 최대 요청 예산액 출력
        if (totalBudget <= m) {
            bw.write(String.valueOf(maxBudget));
        } else {

            // 아니라면 이분 탐색
            int left = 0;
            int right = maxBudget;
            int answer = 0;

            while (left <= right) {

                int mid = (left + right) / 2;

                int expectedTotalBudget = 0;

                // 핵심 1.
                // 값이 상한액과 같거나 작으면
                // 해당 예산 요청액을 그대로 예상합계 예산액에 추가
                // 아니라면?
                // 상한액만큼을 예상합계 예산액에 추가
                for (int i = 0; i < arr.length; i++) {
                    if (arr[i] <= mid) {
                        expectedTotalBudget += arr[i];
                    } else {
                        expectedTotalBudget += mid;
                    }
                }


                // 판별할 시간
                // 국가 예산 총액보다 예상합계 예상액이 같거나 작으면
                // 해당 상한액을 킵하고
                // 해당 상한액부터 아래까지는 다 요구사항 충족하니까 + 1 해서 다시 돌려
                if (expectedTotalBudget <= m) {
                    answer = mid;
                    left = mid + 1;
                } else {
                    // 국가 예산 총액보다 예상합계 예상액이 크면
                    // 해당 상한액 이상은 전부 예산을 초과하니까 볼 필요가 없음
                    // 1빼고 그 범위로 다시 탐색
                    right = mid - 1;
                }

            }

            bw.write(String.valueOf(answer));


        }



        bw.close();
        br.close();
    }


}
