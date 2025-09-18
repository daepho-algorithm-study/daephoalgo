package SWEA;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class S1208 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int tc = 10;

		for (int i = 0; i < tc; i++) {
			int dump_count = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] arr = new int[100];
			for (int j = 0; j < 100; j++) {
				arr[j] = Integer.parseInt(st.nextToken());
			}

			for (int d = 0; d < dump_count; d++) {
				int maxIndex = 0;
				int minIndex = 0;

				for (int j = 0; j < 100; j++) {
					if (arr[j] > arr[maxIndex]) {
						maxIndex = j;
					}
					if (arr[j] < arr[minIndex]) {
						minIndex = j;
					}
				}

				if (arr[maxIndex] - arr[minIndex] <= 1) {
					break;
				}
				arr[maxIndex]--;
				arr[minIndex]++;
			}

			int maximum = arr[0];
			int minimum = arr[0];
			for (int j = 1; j < 100; j++) {
				maximum = Math.max(maximum, arr[j]);
				minimum = Math.min(minimum, arr[j]);
			}

			bw.write("#" + (i + 1) + " " + (maximum - minimum) + "\n");
		}

		bw.close();
		br.close();
	}
}
