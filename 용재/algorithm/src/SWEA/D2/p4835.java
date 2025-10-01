package SWEA.D2;

import java.util.Scanner;

public class p4835 { // SWEA 4835번 문제, 구간합
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int i = 1; i < t + 1; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = sc.nextInt();
            }

            int max_sum = 0;
            int min_sum = 999999999;

            for (int k = 0; k < n-m+1; k++) {
                int sum = 0;
                for (int q = k; q < m+k; q++) {
                    sum += arr[q];
                }
                if (max_sum < sum) {
                    max_sum = sum;
                }
                if (min_sum > sum) {
                    min_sum = sum;
                }
            }

            System.out.println("#" + i + " " + (max_sum-min_sum));
        }
    }
}
