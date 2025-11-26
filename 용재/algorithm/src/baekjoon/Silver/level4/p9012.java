package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

public class p9012 { // 9012번 문제, 괄호 (스택, 큐, 덱 1)
    /*
    괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
    그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
    한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
    그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
    예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.
    여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());


        for (int i = 0; i < T; i++) {
            String n = br.readLine();
            System.out.println(vps(n));
        }
    }

    public static String vps(String s) { // vps 판별 함수
        Stack<Character> stack = new Stack<>();

        for (int j = 0; j < s.length(); j++) {

            if (s.charAt(j) == '(') { // '(' 면 일단 넣음
                stack.push(s.charAt(j));
            } else { // ')' 순서
                if (stack.isEmpty()) {// 스택이 빈 상태
                    return "NO"; // 비었는데 ')'가 들어오면 추가 확인할 필요 없으니 그냥 no 판별
                } else if (stack.peek() == '(') {  // ')'가 들어온 경우 // 스택의 마지막이 '('면 짝이 맞으니까 해당 인자 pop
                    stack.pop();
                }
            }

        }

        // 루프가 끝난 시점에서 스택이 비었으면 vps임
        if (stack.isEmpty()) {
            return "YES";
        } else {
            return "NO";
        }

    }
}
