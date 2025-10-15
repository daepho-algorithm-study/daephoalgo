package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S12741 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            int start = Math.max(a, c);
            int end = Math.min(b, d);
            int answer = Math.max(0, end - start);

            bw.write("#" + test + " " + answer + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
