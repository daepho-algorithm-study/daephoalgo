package CodeTree.Trail_0.Chapter_10.Lesson_4;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class C2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int input = Integer.parseInt(br.readLine());

        for (int row = 0; row < input; row++) {
            for (int col = 1; col <= input; col++) {
                if (col % 2 == 1) {
                    bw.write(String.valueOf(row + 1));
                } else {
                    bw.write(String.valueOf(input - row));
                }
            }
            bw.write("\n");
        }


        bw.close();
        br.close();
    }


}

