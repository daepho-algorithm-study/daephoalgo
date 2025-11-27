package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

/*
모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
입력의 종료조건으로 맨 마지막에 온점 하나(".")가 들어온다.
 */
public class p4949 { // 백준 4949번 문제, 균형잡힌 세상 (스택, 큐, 덱 1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String words = br.readLine();
            if (words.charAt(0) == '.') { // 온점 하나만 찍히면 종료
                break;
            }
            System.out.println(solve(words));
        }


    }

    public static String solve(String s) { // 판별 함수
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push('(');
            } else if (s.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    return "no";
                } else if (stack.peek() == '(') {
                    stack.pop();
                } else { // 스택이 비어있지 않으면서 최상단이 '('가 아닐 때 (최상단이 [ 면 균형이 안맞음)
                    return "no";
                }
            } else if (s.charAt(i) == '[') {
                stack.push('[');
            } else if (s.charAt(i) == ']') {
                if (stack.isEmpty()) {
                    return "no";
                } else if (stack.peek() == '[') {
                    stack.pop();
                } else {
                    return "no";
                }
            } else {
                continue;
            }
        }
        // 여기서 리턴해야함
        if (stack.isEmpty()) {
            return "yes";
        } else {
            return "no";
        }
    }

}
