package baekJoon;

import java.io.*;

public class B24263 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        // 코드 n번 수행
        int codeCnt = n;

        // n에 비례
        int high = 1;

        bw.write(String.valueOf(codeCnt));
        bw.newLine();
        bw.write(high + "\n");


        br.close();
        bw.close();
    }
}