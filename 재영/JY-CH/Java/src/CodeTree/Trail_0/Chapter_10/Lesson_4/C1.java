package CodeTree.Trail_0.Chapter_10.Lesson_4;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class C1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int input = Integer.parseInt(br.readLine());

        for (int num = 1; num <= input; num++) {

            if (num % 2 == 1) {
                for (int odd = 1; odd <= input; odd++) {
                    bw.write(String.valueOf(odd));
                }
            } else {
                for (int even = 0; even < input; even++) {
                    bw.write(String.valueOf(input - even));
                }
            }
            bw.write("\n");
        }


        bw.close();
        br.close();
    }


}