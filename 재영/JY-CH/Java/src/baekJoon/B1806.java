package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            arr[i] = Integer.parseInt(st.nextToken());

        }
        
        // 시작점, 이동할 점, 정답, 합
        int left = 0;
        int right = 0;
        int answer = Integer.MAX_VALUE;
        int sum = 0;
        
        // 이동할점이 n보다 작으면 계속 사용
        while (right < n) {
            
            sum += arr[right];
            
            // 합이 타깃 넘버보다 크거나 같으면
            while (sum >= s) {
                
                // 현재 정답값과 길이 비교
                // 정답보다 작으면 교체
                if (answer > right - left + 1) {
                    answer = right - left + 1;
                }
                
                // 합에서 처음 더해진값을 빼고
                sum -= arr[left];
                // 앞자리 +1
                left += 1;

            }

            // 끝나면 자리수 ++
            right++;

        }

        // 만약 못 해당 조건을 만족하는 길이값이 없다면
        // 0을
        if (answer == Integer.MAX_VALUE) {
            bw.write(String.valueOf(0));
            // 아니라면 답을 출력
        } else {
            bw.write(String.valueOf(answer));
        }







        bw.close();
        br.close();
    }


}
