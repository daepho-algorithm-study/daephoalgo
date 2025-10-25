package baekJoon;

import java.io.*;

public class B2292 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 1 7 19 37
        // 6 12 18

        int input = Integer.parseInt(br.readLine());

        int num = 1;
        int cnt = 1;

        while (true) {

            num = num + 6 * (cnt - 1);

            if (input <= num) {
                bw.write(String.valueOf(cnt));
                break;
            }

            cnt++;

        }



        bw.close();
        br.close();
    }


}
