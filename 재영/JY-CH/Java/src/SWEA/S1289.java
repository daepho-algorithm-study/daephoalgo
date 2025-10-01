package SWEA;

import java.io.*;

public class S1289 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            // 1자씩 뜯어서 배열로
            char[] targetArr = br.readLine().toCharArray();

            int[] arr = new int[targetArr.length];

            int cnt = 0;

            for (int i = 0; i < targetArr.length; i++) {
                // 사실상 이줄이 핵심
                // int로 배열을 형성했으니까 String으로, char 역시 String으로 형변환 하고 같은지 다른지 비교해주기
                if (!String.valueOf(arr[i]).equals(String.valueOf(targetArr[i]))) {
                    if (targetArr[i] == '1') {
                    for (int j = i; j < targetArr.length; j++) {
                        arr[j] = 1;
                        }
                    } else {
                        for (int j = i; j < targetArr.length; j++) {
                            arr[j] = 0;
                        }
                    }
                    cnt++;
                }
            }

            bw.write("#" + test + " " + cnt + "\n");

        }


        bw.close();
        br.close();
    }


}
