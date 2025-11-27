package baekJoon;

import java.io.*;

public class B10870 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        // long 안써도됨, 20번째 피보나치 수는 6765
        int answer = fibo(n);

        bw.write(String.valueOf(answer));

        br.close();
        bw.close();
    }

    // 재귀 함수
    // 피보나치 수는 첫 시작 2자리만 알려주면 재귀 가능!
    public static int fibo(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibo(n - 1) + fibo(n - 2);
    }
}

