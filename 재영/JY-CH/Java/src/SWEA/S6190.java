package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S6190 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int test = 1; test <= tc; test++) {
            int n = Integer.parseInt(br.readLine());


            StringTokenizer st = new StringTokenizer(br.readLine());

            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            // 조건을 통과하는 수가 없을 경우
            // -1 을 출력할 수 있도록
            int answer = -1;

            for (int i = 0; i < arr.length - 1; i++) {
                for (int j = i + 1; j < arr.length; j++) {
                    String check = Integer.toString(arr[i] * arr[j]);

                    // 수를 체크할 boolean
                    boolean checkStatus = true;

                    int compareMax = 0;

                    for (int k = 0; k < check.length() - 1; k++) {
                        // 자릿수들을 비교하여 조건에 어긋날경우
                        // boolean false
                        if (check.charAt(k) > check.charAt(k + 1)) {
                            checkStatus = false;
                            break;
                        }
                    }

                    // true
                    // 비교할 현재 수와 answer를 비교해서 제일 높은값을 가져감
                    if (checkStatus) {
                        compareMax = Integer.parseInt(check);
                        answer = Math.max(answer, compareMax);
                    }

                }
            }

            bw.write("#" + test + " " + answer + "\n");



        }



        bw.close();
        br.close();
    }
}
