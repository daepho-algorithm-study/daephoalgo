package codingTest.greedyAlgorithm;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class CT_3_4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int answer = 0;
        // 1이면 할필요없다 1보다 클때만 돌자
        while (n > 1) {
            
            // n 이 k 로 나눠 떨어지면
            // n을 k의 몫으로 바꾼다
            if (n % k == 0) {
                n = n / k;
            } else {
                // 아니면 n에서 1뺀다
                n = n - 1;
            }
            
            // 돌때마다 1씩 더한다
            answer++;

        }

        bw.write(String.valueOf(answer));


        bw.close();
        br.close();
    }


}
