package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class B4779 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 4779 칸토어 집합


        // 입력이 몇개가 들어올지 모름
        String input;
        // null이 아니고 빈줄이 아니라면 종료하게끔
        // readline은 문자열을 반환, 입력이 끝나면 null을 반환 (EOF)
        // 2번째의 경우 빈줄, 공백 입력시에도 종료 될 수 있도록 하기 위해
         while ((input = br.readLine()) != null && !input.isBlank()) {

            int n = Integer.parseInt(input);
            
            // 초기 변수
            int num = 1;
            
            // 입력값에 따른 변수 조정
            // 제곱수 만들기 
            while (n > 0) {
                num *= 3;
                n -= 1;
            }

            // n은 곧 제곱수이면서 동시에 입력값을 결정하는 변수로 활용
            while (n < num) {

                if (check(n)) {
                    bw.write(" ");
                } else {
                    bw.write("-");
                }

                n++;

            }

            bw.write("\n");
        }

        bw.close();
        br.close();
    }

    // 재귀함수
    public static boolean check(int number) {
        
        // 0보다 크면
        while (number > 0) {
            
            // 나머지가 1이면 전부 공백으로
            if (number % 3 == 1) {
                return true;
            }
            // 수가 커도 재귀를 통한 몫을 이용하여 확인
            number /= 3;
        }

        return false;
    }


}
