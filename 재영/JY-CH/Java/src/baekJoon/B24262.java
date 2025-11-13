package baekJoon;

import java.io.*;

public class B24262 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int codeCnt = 1;
        
        int high = 0;

        bw.write(String.valueOf(codeCnt));
        bw.newLine();
        bw.write(high + "\n");


        br.close();
        bw.close();
    }
}