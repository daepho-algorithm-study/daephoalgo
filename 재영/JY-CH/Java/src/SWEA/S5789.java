package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S5789 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());

            int[] arr = new int[n] ;

            for (int i = 1; i <= q; i++) {
                st = new StringTokenizer(br.readLine());
                int left = Integer.parseInt(st.nextToken());
                int right = Integer.parseInt(st.nextToken());

                for (int j = left - 1; j < right; j++) {
                    arr[j] = i;
                }

            }

            bw.write("#" + test + " ");

            for (int i = 0; i < arr.length; i++) {
                bw.write(arr[i] + " ");
            }

            bw.newLine();
        }


        bw.close();
        br.close();
    }


}
