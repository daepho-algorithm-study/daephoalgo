package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B2501 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 2501. 약수 구하기

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int cnt = 0;
        int num = 0;

        for (int i = 1; i <= n; i++) {

            // 약수면 카운트 올리고 , 해당 약수 저장
            if (n % i == 0) {

                cnt++;

                num = i;
            }

            // 약수 갯수랑 원하는 수랑 같아지면 멈춤
            if (cnt == k) {
                break;
            }

        }

        // 원하는 약수 보다 계산된 약수가 작으면
        if (cnt < k) {

            bw.write(String.valueOf(0));
        // 크면
        } else {

            bw.write(String.valueOf(num));

        }


        bw.close();
        br.close();
    }


}
