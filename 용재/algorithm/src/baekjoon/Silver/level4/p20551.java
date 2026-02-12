package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p20551 { // 백준 20551번 문제, Sort 마스터 배지훈의 후계자
    static int n, m;
    static int[] numbers, quest;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        numbers = new int[n];
        quest = new int[m];

        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(br.readLine()); // n개의 원소를 가진 배열 A
        }

        Arrays.sort(numbers); // A의 원소가 오름차순 정렬된 배열 B
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < m; j++) {
            quest[j] = Integer.parseInt(br.readLine()); // M 개의 질문을 하기 위한 정수 D
            sb.append(binary(numbers, quest[j])).append("\n");
        }

        System.out.print(sb);
    }

    static int binary(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        int result = -1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] < target) {
                start = mid + 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                end = mid -1;
                result = mid;
            }
        }

        return result;
    }

}
