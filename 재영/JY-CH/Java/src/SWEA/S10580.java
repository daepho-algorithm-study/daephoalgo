package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S10580 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            int lineNumber = Integer.parseInt(br.readLine());


            int[][] arr = new int[lineNumber][2];

            for (int i = 0; i < lineNumber; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 2; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }


            int answer = 0;
            // 마지막 줄은 어차피 비교가 필요가 없음 lineNumber -1 의 이유
            for (int i = 0; i < lineNumber - 1; i++) {
                for (int j = i + 1; j < lineNumber; j++) {
                    // 조건 1
                    // 시작점이 비교하는 시작점보다 작을때, 도착점이 비교하는 도착점 보다 클경우
                    // 조건 2
                    // 시작점이 비교하는 시작점보다 클때, 도착점이 비교하는 도착점 보다 작을 경우
                    if ((arr[i][0] < arr[j][0] && arr[i][1] > arr[j][1]) || (arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1])) {
                        answer++;
                    }
                }
            }

            bw.write("#" + test + " " + answer + "\n");

        }



        bw.close();
        br.close();
    }


}
