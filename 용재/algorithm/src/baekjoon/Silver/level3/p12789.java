package baekjoon.Silver.level3;

import java.util.*;
import java.io.*;

public class p12789 { // 백준 12789번 문제, 도키도키 간식드리미 (큐, 스택, 덱 1)
    /*
    사람들은 현재 1열로 줄을 서있고, 맨 앞의 사람만 이동이 가능하다.
    인규는 번호표 순서대로만 통과할 수 있는 라인을 만들어 두었다.
    이 라인과 대기열의 맨 앞 사람 사이에는 한 사람씩 1열이 들어갈 수 있는 공간이 있다.
    현재 대기열의 사람들은 이 공간으로 올 수 있지만 반대는 불가능하다.
    승환이를 도와 프로그램을 완성하라.
    승환이가 무사히 간식을 받을 수 있으면 "Nice"(따옴표는 제외)를 출력하고
    그렇지 않다면 "Sad"(따옴표는 제외)를 출력한다.
     */

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();
        int now = 0;

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(st.nextToken());
            if (x == now + 1) { // 숫자 받을때 자기 순서면 지나가고
                now++;
                while (!stack.isEmpty() && stack.peek() == now + 1) {
                    stack.pop();
                    now++;
                }
            } else { // 자기순서 아니면 대기 위치에 있기
                stack.push(x);
            }

        }

        int size = stack.size();
        for (int i = 0; i < size; i++) {
            if (stack.peek() == now + 1) { // 최상단 보고 현재까지 받은 사람 +1이면 now 늘리고 빠지기
                now++;
                stack.pop();
            }
        }

        String result = "";
        if (stack.isEmpty()) { // 비었으면 nice, 아니면 sad
            result = "Nice";
        } else {
            result = "Sad";
        }

        System.out.print(result);
    }

}
