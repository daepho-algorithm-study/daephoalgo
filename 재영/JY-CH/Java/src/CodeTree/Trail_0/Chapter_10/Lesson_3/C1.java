package CodeTree.Trail_0.Chapter_10.Lesson_3;

import java.io.*;
import java.util.StringTokenizer;

public class C1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int row = 0; row < 4; row++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int answer = 0;
            for (int col = 0; col < 4; col++) {
                answer += Integer.parseInt(st.nextToken());
            }
            bw.write(answer + "\n");
        }

        br.close();
        bw.close();


    }
}
