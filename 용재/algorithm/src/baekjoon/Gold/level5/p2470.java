package baekjoon.Gold.level5;

import java.io.*;
import java.util.*;

public class p2470 { // 백준 2470번 문제, 두 용액
    static int n;
    static int[] arr;
    static int minAbs = Integer.MAX_VALUE;
    static int[] resultArr = new int[2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        for (int j = 0; j < n - 1; j++) {
            binary(arr[j], j);
        }

        System.out.print(resultArr[0] + " " + resultArr[1]);


    }

    static void binary(int fixedValue, int startIndex) {
        int start = startIndex + 1;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int sum = fixedValue + arr[mid]; // 무조건 더하면됨 양수끼리라고 -하면 안되는거였음

            // 1. 최저 값 갱신 
            if (Math.abs(sum) < minAbs) {
                minAbs = Math.abs(sum);
                resultArr[0] = fixedValue;
                resultArr[1] = arr[mid];
            }

            // 2. 이분 탐색 방향 결정 
            if (sum < 0) {
                // 합이 음수면, 0에 가까워지기 위해 더 큰 수를 더해야 함 -> 오른쪽 이동
                start = mid + 1;
            } else if (sum > 0) {
                // 합이 양수면, 0에 가까워지기 위해 더 작은 수를 더해야 함 -> 왼쪽 이동
                end = mid - 1;
            } else {
                // 합이 0이면 더 이상 볼 필요 없음  -> 종료
                return;
            }
        }

    }
}
