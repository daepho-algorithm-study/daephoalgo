package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p10773 { // 백준 10773번 문제, 제로 (스택, 큐, 덱 1)
    /* 첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
    이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
    정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K = Integer.parseInt(br.readLine());

        Stack<Integer> stack = new Stack<>();
        int result = 0;
        for (int i = 0; i < K; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x != 0) {
                stack.push(x);
                result += x;
            } else {
                result -= stack.pop();
            }
        }
        System.out.print(result);
    }
}
