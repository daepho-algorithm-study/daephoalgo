package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p18258 { // 백준 18258번 문제, 큐2 (스택, 큐, 덱 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<>();
        int lastNum = -1; // 마지막 숫자를 알기위한 변수

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String order = st.nextToken();
            if (order.equals("push")) { //push X: 정수 X를 큐에 넣는 연산이다.
                int x = Integer.parseInt(st.nextToken());
                q.add(x);
                lastNum = x;
            } else if (order.equals("pop")) {
                if (q.isEmpty()) { //pop: 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                    sb.append(-1).append("\n");
                } else { // 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
                    sb.append(q.poll()).append("\n");
                }
            } else if (order.equals("size")) { //size: 큐에 들어있는 정수의 개수를 출력한다.
                sb.append(q.size()).append("\n");
            } else if (order.equals("empty")) {
                if (q.isEmpty()) { // empty: 큐가 비어있으면 1,
                    sb.append(1).append("\n");
                } else { // 아니면 0을 출력한다.
                    sb.append(0).append("\n");
                }
            } else if (order.equals("front")) {
                if (!q.isEmpty()) { // front: 큐의 가장 앞에 있는 정수를 출력한다.
                    sb.append(q.peek()).append("\n");
                } else { // 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                    sb.append(-1).append("\n");
                }
            } else {
                if (!q.isEmpty()) { // back: 큐의 가장 뒤에 있는 정수를 출력한다.
                    sb.append(lastNum).append("\n");
                } else { //만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                    sb.append(-1).append("\n");
                }
            }
        }
        System.out.print(sb);
    }
}
