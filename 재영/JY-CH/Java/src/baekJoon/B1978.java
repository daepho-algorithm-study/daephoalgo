package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B1978 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 1978. 소수 찾기

        // 확인할 수의 갯수
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        // 카운트할 변수
        int answer = 0;

        // 소수확인 시작
        for (int i = 0; i < n; i++) {

            int num = Integer.parseInt(st.nextToken());

            // 2보다 클때
            if (num > 2) {
                boolean check = true;
                // 2부터 확인하려는 수 - 1까지
                // 1개라도 나눠떨어지면 소수가 아님
                for (int j = 2; j < num; j++) {
                    if (num % j == 0) {
                        check = false;
                    }
                }

                if (check) {
                    answer++;
                }

            } else if (num == 2) {
                answer++;
            }

        }

        bw.write(String.valueOf(answer));


        bw.close();
        br.close();
    }


}
