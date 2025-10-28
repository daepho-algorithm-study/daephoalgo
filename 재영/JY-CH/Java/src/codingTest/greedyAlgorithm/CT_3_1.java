package codingTest.greedyAlgorithm;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class CT_3_1 {
    public static void main(String[] args) throws IOException {
        // 거스름돈

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 문제 예시는 1260원
        // input을 받을 수 있도록 바꾼부분
        int money = Integer.parseInt(br.readLine());
        
        int[] changeGroup = {500, 100, 50, 10};

        int coinCnt = 0;

        for (int i = 0; i < changeGroup.length; i++) {

            int change = changeGroup[i];

            if (money - change >= 0) {
                coinCnt = coinCnt + (money / change);
                money = money % change;
            }

        }

        bw.write(String.valueOf(coinCnt));


        bw.close();
        br.close();
    }
}
