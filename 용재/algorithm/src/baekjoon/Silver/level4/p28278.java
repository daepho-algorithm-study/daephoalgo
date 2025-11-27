package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

public class p28278 { // 백준 28278번 문제, 스택 2 (스택, 큐, 덱 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Stack<Integer> stackInt = new Stack<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int order = Integer.parseInt(st.nextToken());
            switch (order) {
                case 1: // 1 x  정수 x를 스택에 넣는다
                    int x = Integer.parseInt(st.nextToken());
                    stackInt.push(x);
                    break;
                case 2:
                    if (!stackInt.isEmpty()) { // 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다.
                        bw.write(String.valueOf(stackInt.pop()));
                        bw.write("\n");
                        bw.flush();
                        break;

                    } else { // 없다면 -1을 대신 출력한다.
                        bw.write(String.valueOf(-1));
                        bw.write("\n");
                        bw.flush();
                        break;
                    }
                case 3: // 스택에 들어있는 정수의 개수를 출력한다.
                    bw.write(String.valueOf(stackInt.size()));
                    bw.write("\n");
                    bw.flush();
                    break;
                case 4: // 스택이 비어있으면 1, 아니면 0을 출력한다.
                    if (stackInt.isEmpty()) {
                        bw.write(String.valueOf(1));
                        bw.write("\n");
                        bw.flush();
                        break;
                    } else {
                        bw.write(String.valueOf(0));
                        bw.write("\n");
                        bw.flush();
                        break;
                    }
                case 5:
                    if (!stackInt.isEmpty()) {// 스택에 정수가 있다면 맨 위의 정수를 출력한다.
                        bw.write(String.valueOf(stackInt.peek()));
                        bw.write("\n");
                        bw.flush();
                        break;
                    } else {// 없다면 -1을 대신 출력한다.
                        bw.write(String.valueOf(-1));
                        bw.write("\n");
                        bw.flush();
                        break;
                    }
            }
        }
        br.close();
        bw.close();

    }
}
