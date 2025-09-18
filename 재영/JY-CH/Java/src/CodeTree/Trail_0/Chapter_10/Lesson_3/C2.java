package CodeTree.Trail_0.Chapter_10.Lesson_3;

import java.io.*;
import java.util.StringTokenizer;


public class C2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int cnt = 0;
        for (int row = 0; row < 4; row++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int col = 0; col < 4; col++) {
                int input = Integer.parseInt(st.nextToken());
                if (input % 5 == 0) {
                    cnt++;
                }
            }
        }
        bw.write(String.valueOf(cnt));

        br.close();
        bw.close();
    }
}
