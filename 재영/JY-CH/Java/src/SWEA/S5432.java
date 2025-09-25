package SWEA;

import java.io.*;

public class S5432 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {

            // charArray로 받아야됨;;
            // 이렇게 안받으면 앞에 공백 받고 들어오는등의 기묘한 문제가 발생함;;
            char[] arr = br.readLine().toCharArray();

            // 답
            // 줄 카운트 할 변수
            int answer = 0;
            int line = 0;

            for (int i = 0; i < arr.length; i++) {
                // arr[i]는 String이 아닌 Char
                // char 리터럴은 작은 따옴표로 해결해야함;;

                // 괄호가 열려있을경우
                // 닫힌 부분이 ) 면 레이저니까
                // 답에 현재 줄의 갯수만큼 늘리고.
                // '지금 돌고 있는 배열의 인덱스를 추가해서 돌려야된다!' <- 핵심
                // 아니면 줄 하나 느는거고
                if (arr[i] == '(') {
                    if (i + 1 < arr.length && arr[i + 1] == ')') {
                        answer += line;
                        i++;
                    } else {
                        line++;
                    }
                    // 닫힌 괄호
                    // 레이저일때는 이미 위에서 처리해줌.
                    // 이때는 line을 줄이고 그 라인을 답에다가 담아준다.
                } else {
                    line--;
                    answer++;
                }
            }



            bw.write("#" + test + " " + answer + "\n");
        }




        bw.close();
        br.close();
    }


}
