package SWEA;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class S12510 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine()); // 테스트 케이스 개수

        for (int test = 1; test <= tc; test++) {
            int n = Integer.parseInt(br.readLine()); // 숫자의 개수
            int[] arr = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            // 정렬
            Arrays.sort(arr);

            // 양 끝에서 번갈아 가며 값 선택
            List<Integer> result = new ArrayList<>();
            int left = 0;
            int right = n - 1;

            while (result.size() < 10 && left <= right) {
                if (result.size() < 10) {
                    result.add(arr[right]);
                    right--;
                }
                if (result.size() < 10 && left <= right) {
                    result.add(arr[left]);
                    left++;
                }
            }

            // 결과 출력
            bw.write("#" + test);
            for (int i = 0; i < result.size(); i++) {
                int num = result.get(i);
                bw.write(" " + num);
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
