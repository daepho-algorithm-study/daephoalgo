package codingTest.greedyAlgorithm;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class CT_3_3 {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int[][] field = new int[n][m];

    for (int i = 0 ; i < n; i++) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < m; j++) {
            field[i][j] = Integer.parseInt(st.nextToken());
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int lowNum = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            int compareNum = field[i][j];
            if (lowNum > compareNum) {
                lowNum = compareNum;
            }
        }

        if (answer < lowNum) {
            answer = lowNum;
        }
    }

    bw.write(String.valueOf(answer));


    bw.close();
    br.close();
}


}