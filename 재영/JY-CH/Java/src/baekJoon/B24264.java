package baekJoon;

import java.io.*;

public class B24264 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        // 코드 n * n번 수행
        // 근데 n이 5만까지라 long으로 처리해야됨;;
        long codeCnt = (long) n * n;

        // n * n에 비례
        int high = 2;

        bw.write(String.valueOf(codeCnt));
        bw.newLine();
        bw.write(high + "\n");


        br.close();
        bw.close();
    }
}