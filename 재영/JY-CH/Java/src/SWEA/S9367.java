package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S9367 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            int n = Integer.parseInt(br.readLine());

            int[] arr = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            int answer = 0;

            // 크기만 하면 된다..
            // 1씩 커지란 말 없었다..
            int cnt = 0;
            for (int i = 0; i < (arr.length - 1); i++) {
                if (arr[i] < arr[i+1]) {
                    cnt++;
                } else {
                    answer = Math.max(answer, cnt);
                    cnt = 0;
                }
            }
            // 최소값이 1이라 더해줘야됨
            answer = Math.max(answer, cnt) + 1;

            bw.write("#" + test + " " + answer + "\n");
        }



        bw.close();
        br.close();
    }


}
