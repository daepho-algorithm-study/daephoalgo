package baekJoon;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class B9506 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {

            int n = Integer.parseInt(br.readLine());

            if (n == -1) {
                break;
            }

            List<Integer> numList = new ArrayList<>();

            int sum = 0;

            for (int i = 1; i <= n; i++) {

                if (n % i == 0) {
                    if (i != n) {
                        numList.add(i);
                        sum += i;
                    }
                }

            }

            if (sum == n) {
                bw.write(n + " " + "=" + " ");
                for (int i = 0; i < numList.size(); i++) {
                    if (i == 0) {
                        bw.write(numList.get(i) + " ");
                    } else {
                        bw.write("+ " + numList.get(i) + " ");
                    }
                }
            } else {
                bw.write(n + " " + "is NOT perfect.");
            }

            bw.write("\n");




        }

        bw.close();
        br.close();
    }


}