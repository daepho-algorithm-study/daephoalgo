package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p10816 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        HashMap<Integer, Integer> cards = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int inputNumber = Integer.parseInt(st.nextToken());
            cards.put(inputNumber, cards.getOrDefault(inputNumber, 0) + 1);
        }
//        System.out.println(cards);

        int M = Integer.parseInt(br.readLine());
        int[] arr = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < M; j++) {
            arr[j] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();

        for (int s = 0; s<M; s++) {
            sb.append(cards.getOrDefault(arr[s],0));
            sb.append(" ");
        }

        bw.write(sb.toString());

        br.close();
        bw.close();
//        int[] result = new int[M];
//
//        for (int s = 0; s<M; s++) {
//            result[s] = cards.getOrDefault(arr[s],0);
//            System.out.print(result[s]+ " "); -> 빈번한 입출력으로 인해 시간초과 발생(추정)
//                                                 그래서 StringBuilder로 한번에 합쳐서 출력
//        }
//        System.out.println(Arrays.toString(result));

    }
}
