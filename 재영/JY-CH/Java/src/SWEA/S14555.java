package SWEA;

import java.io.*;

public class S14555 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            char[] arr = br.readLine().toCharArray();


            // '(' 나오면 무조건 + 1
            // ')' 나왔을때 앞에 '|' 이거면 + 1

            int circle = 0;

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == '(') {
                    circle++;
                } else if (arr[i] == ')' && arr[i-1] == '|') {
                    circle++;
                }
            }

            bw.write("#" + test + " " + circle + "\n");



        }


        bw.close();
        br.close();
    }


}

