package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p24511 { // 백준 24511번 문제, queuestack (큐, 스택, 덱 1)
    /*
    첫째 줄에 queuestack을 구성하는 자료구조의 개수 N이 주어진다. (1 <= N <= 100,000)
    둘째 줄에 길이 N의 수열 A가 주어진다. i번 자료구조가 큐라면 A_i = 0, 스택이라면 A_i = 1이다.
    셋째 줄에 길이 N의 수열 B가 주어진다. B_i는 i번 자료구조에 들어 있는 원소이다. (1 <= B_i <= 1,000,000,000)
    넷째 줄에 삽입할 수열의 길이 M이 주어진다. (1 <= M <= 100,000)
    다섯째 줄에 queuestack에 삽입할 원소를 담고 있는 길이 M의 수열 C가 주어진다. (1 <= C_i <= 1,000,000,000)
    입력으로 주어지는 모든 수는 정수이다.
    4
    0 1 1 0
    1 2 3 4
    3
    2 4 7
    ** 4 1 2
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int[] typeArr = new int[N]; // 자료구조 종류 (0: 큐, 1: 스택)

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            typeArr[i] = Integer.parseInt(st.nextToken());
        }

        Deque<Integer> deque = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int val = Integer.parseInt(st.nextToken());
            // 큐(0)인 경우에만 Deque에 추가
            if (typeArr[i] == 0) {
                deque.addFirst(val);
            }
        }

        int M = Integer.parseInt(br.readLine()); // 삽입할 수열 길이
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < M; i++) {
            int newNum = Integer.parseInt(st.nextToken());

            // 새로운 값은 큐의 입구(Last)로 들어옴
            deque.addLast(newNum);

            // 가장 앞에 있는 값(출구 쪽)을 빼서 출력
            sb.append(deque.pollFirst()).append(" ");
        }

        System.out.println(sb);
    }
}
