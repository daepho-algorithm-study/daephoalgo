package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class B2447 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 2477 별찍기 - 10
        // n은 3의 제곱수다
        // 3 9 27
        int n = Integer.parseInt(br.readLine());

        // 별 찍을 함수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // 별과 공백을 선택할 함수
                if (check(i,j)) {
                    bw.write(" ");
                } else {
                    bw.write("*");
                }

            }
            bw.write("\n");
        }



        bw.close();
        br.close();
    }
    
    // 핵심
    public static boolean check(int i, int j) {
        // 2차원 배열기준
        // 가로 세로 좌표의 나머지가 1이면 빈 값이다
        // ex) 의 경우 1,1은 비워져야된다
        // 수가 커질 경우 재귀를 통해 수를 몫으로 줄여주고
        // 해당 블록이 비워져야하는지 판단한다
        while (i > 0 && j > 0) {
            if (i % 3 == 1 && j % 3 == 1) {
                return true;
            }
            i = i / 3;
            j = j / 3;
        }
        return false;
    }


}
