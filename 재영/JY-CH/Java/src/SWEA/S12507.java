package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S12507 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int p = Integer.parseInt(st.nextToken());
            int pa = Integer.parseInt(st.nextToken());
            int pb = Integer.parseInt(st.nextToken());

            // A 이진 탐색
            int aCount = 0;
            int left = 1;
            int right = p;

            while (left <= right) {
                int mid = (left + right) / 2;
                aCount++;

                if (mid == pa) {
                    break;
                } else if (mid < pa) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            // B 이진 탐색
            int bCount = 0;
            left = 1;
            right = p;

            while (left <= right) {
                int mid = (left + right) / 2;
                bCount++;

                if (mid == pb) {
                    break;
                } else if (mid < pb) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            // 결과 저장할 변수
            String result;

            if (aCount < bCount) {
                result = "A";
            } else if (aCount > bCount) {
                result = "B";
            } else {
                result = "0";
            }
            
            bw.write("#" + test + " " + result + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
