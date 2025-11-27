package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B27433 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        // 또 long이야.?
        long answer = 1;

        // 반복해서 곱해준다
        for (int i = 1; i <= n; i++) {
            answer *= i;
        }

        bw.write(String.valueOf(answer));

        br.close();
        bw.close();
    }
}

