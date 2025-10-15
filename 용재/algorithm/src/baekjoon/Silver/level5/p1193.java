package baekjoon.Silver.level5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1193 { // 백준 1193 문제, 분수찾기 (수학 1)
    public static void main(String[] args) throws IOException { //
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x = Integer.parseInt(br.readLine()); // readLine() 으로 읽고 정수형으로 변환
        br.close();

        int line = 1;
        int cnt = 0;

        while (true) {
            cnt = line * (line + 1) / 2; // 1부터 라인의 총 갯수 만큼 덧셈
            if (x <= cnt) {
                break;
            }
            line++;
        }

        int prevLineCnt = (line - 1) * line / 2;
        int position = x - prevLineCnt;

        int top; // 분자
        int bottom; // 분모

        if (line % 2 == 0) { // 대각 번호가 짝수일 때
            top = position;
            bottom = line - position + 1;
        } else {
            top = line - position + 1;
            bottom = position;
        }

        System.out.print(top + "/" + bottom);

    }
}
