package baekJoon;

import java.io.*;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B3273 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            arr[i] = Integer.parseInt(st.nextToken());

        }

        int x = Integer.parseInt(br.readLine());

        Arrays.sort(arr);

        int left = 0;
        int right = n - 1;
        int answer = 0;


        while (left < right) {

            if ((arr[left] + arr[right]) == x) {
                answer++;
            }

            if ((arr[left] + arr[right]) >= x) {
                right = right - 1;
            } else if ((arr[left] + arr[right]) < x) {
                left = left + 1;
            }

        }


        bw.write(String.valueOf(answer));





        bw.close();
        br.close();
    }


}
