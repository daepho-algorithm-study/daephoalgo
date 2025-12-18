package baekJoon;

import java.io.*;
import java.util.StringTokenizer;

public class B5086 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if (n == 0) {
                break;
            }

            if (n % m == 0) {
                bw.write("multiple" + "\n");
            } else if (m % n == 0) {
                bw.write("factor" + "\n");
            } else {
                bw.write("neither" + "\n");
            }



        }


        bw.close();
        br.close();
    }


}
