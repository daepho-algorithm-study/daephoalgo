package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S20396 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int i = 1; i <= tc; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            // 돌의 갯수, 바꾸는 횟수
            int stoneNumber = Integer.parseInt(st.nextToken());
            int changeCount = Integer.parseInt(st.nextToken());

            // 배열 정보
            int[] stoneStatus = new int[stoneNumber];

            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < stoneNumber; j++) {
                stoneStatus[j] = Integer.parseInt(st.nextToken());
            }

            // 바꾸기 시작
            for (int l = 0; l < changeCount; l++) {
                st = new StringTokenizer(br.readLine());
                int changeStartIndex = Integer.parseInt(st.nextToken());
                int changeEndIndex = Integer.parseInt(st.nextToken());

                int changeRange = 0;

                // 돌 바꾸는 범위가 배열보다 크면 최대치를 배열 마지막으로
                // 아니라면 뒤집기가 시작되는 인덱스부터 끝나는 인덱스를 범위로
                if (changeStartIndex + changeEndIndex > stoneNumber) {
                    changeRange = stoneNumber;
                } else {
                    changeRange = changeStartIndex + changeEndIndex - 1;
                }

                for (int k = changeStartIndex; k < changeRange; k++) {
                    int color = stoneStatus[k - 1];
                    stoneStatus[k] = color;
                }
            }
            bw.write("#" + i + " ");
            for (int o = 0; o < stoneNumber; o++) {
                bw.write(stoneStatus[o] + " ");
            }
            bw.write("\n");

        }
        br.close();
        bw.close();

    }
}
