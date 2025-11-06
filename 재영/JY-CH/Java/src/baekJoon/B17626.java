package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class B17626 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 제곱수의 합
        // n이 주어질때 n의 최소개수의 합
        // 그리디? 같은데 -> 해봤는데 최적의 해가 아님
        // 근데 그리디에서 계속 못벗어남 코드가 결과적으로
        // 힌트보고 dp 문제인거 알고 해결함

        int n = Integer.parseInt(br.readLine());


        int[] dp = new int[n+1];

        // 디폴트값들
        // 0은 당연히 없다.
        dp[0] = 0;

        for (int i = 1; i < dp.length; i++) {
            
            // 카운트를 최대값으로 설정하고 시작
            int keepCnt = Integer.MAX_VALUE;

            // j를 1부터
            // j의 제곱이 i보다 작을때까지 계속 반복하면서.
            // 이때 현재 킵하고 있는 카운트보다 dp[i - (j*j)] 가 작으면 킵카운트 변경.
            // 12의 경우 4 와 9 를 빼면 dp[8] dp[3] 이렇게 남게 되는데
            // dp[8] = dp[4] + 1 = dp[0] + 1 + 1
            // dp[3] = dp[2] + 1 = dp[1] + 1 + 1 = dp[0] + 1 + 1 + 1
            // keepCnt는 dp[8] 이 횟수가 1회 적어 해당 수를 킵 하고
            // 2제곱인 4를 뺐으니까? dp[4] = 1, dp[12] = dp[8] + dp[4] = 2 + 1;
            for (int j = 1; j * j <= i; j++) {
                if (dp[i - (j * j)] < keepCnt) {
                    keepCnt = dp[i - (j * j)];
                }
            }

            // 현재 설정된 킵카운트는 해당 수를 만들기위해 필요한 최소합임.
            // 근데 우리는 i 에서 j * j 뺀 다음 해당 값을 비교 한거니까
            // 1회 더해줘야함. 제곱수기 때문에 dp[j*j]는 무조건 1임
            dp[i] = keepCnt + 1;
        }


        int answer = dp[n];

        bw.write(String.valueOf(answer));


        bw.close();
        br.close();
        }


    }
