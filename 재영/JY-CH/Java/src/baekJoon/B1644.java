package baekJoon;

import java.io.*;


public class B1644 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 소수의 연속합

        // 타깃 넘버
        int n = Integer.parseInt(br.readLine());

        // 타깃 넘버까지 소수인지 확인해야되서 n + 1
        int[] arr = new int[n + 1];
        
        // 2부터 n까지 쭈욱 1로 채우고
        for (int i = 2; i <= n; i++) {
            arr[i] = 1;
        }

        // 만약 arr[i] == 1이다? => 소수이다?
        // 배수는 소수가 아니다!
        // 에라스토테네스의 체 구현
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 1) {
                for (int j = 2; i * j <= n; j++) {
                    arr[i * j] = 0;
                }
            }
        }
        
        // 투포인터 용 변수, 정답(카운트 변수), 현재 합 저장할 변수
        int left = 0;
        int right = 2;
        int answer = 0;
        int sum = 0;
        
        // 첫번째
        // 우리가 index로 사용할 right는 n보다 클 수 없다
        // right를 index로 가지는 값이 1이다? 얘는 소수다.
        while (right <= n) {
            
            // 소수면 더해요
            if (arr[right] == 1) {
                sum+=right;
            } else {
                // 아니면 올리고 넘어가요
                right++;
                continue;
            }
            
            // 합이 n을 넘었다면
            while (sum > n) {
                
                // left를 이용해서
                // sum이 n보다 작거나 같도록 조정
                if (arr[left] == 1) {
                    sum-=left;
                }
                left++;
            }

            // 합이 n과 같다?
            // answer (연속합 일치하는 횟수 ++)
            if (sum == n) {
                answer++;
            }

            // 끝났으면 다음 수 확인하러.
            right++;


        }
    
        // 이러면 한번도 일치하지 않으면 0, 아니면 answer의 값 출력
        bw.write(String.valueOf(answer));



        bw.close();
        br.close();
    }


}