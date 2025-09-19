package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S22375 {
    public static void main(String[] args) throws IOException {

        // 빠른 입출력을 위한 클래스
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        // 테스트케이스
        int tc = Integer.parseInt(input.readLine());

        for (int i = 1; i <= tc; i++) {

            // 순서대로 스위치 갯수, 처음 스위치 상태, 목표 스위치 상태, 스위치 조작 횟수
            int switchNumber = Integer.parseInt(input.readLine());
            int[] switchStartStatus = new int[switchNumber];
            int[] switchEndStatus = new int[switchNumber];
            int switchCount = 0;


            // 스위치의 상태 정보를 배열에 받아오는중
            StringTokenizer st = new StringTokenizer(input.readLine());
            for (int j = 0; j < switchNumber; j++) {
                switchStartStatus[j] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(input.readLine());
            for (int j = 0; j < switchNumber; j++) {
                switchEndStatus[j] = Integer.parseInt(st.nextToken());
            }


            // 스위치 배열의 모든 인덱스를 순회
            for (int k = 0; k < switchNumber; k++) {
                // 만약 현재 스위치와 목표 스위치의 상태 정보가 다르다면
                if (switchStartStatus[k] != switchEndStatus[k]) {
                    // 스위치 조작 횟수를 1 증가
                    switchCount++;
                    // 해당 인덱스부터 배열의 마지막 인덱스까지 상태정보 변경
                    for (int l = k; l < switchNumber; l++) {
                        if (switchStartStatus[l] == 1) {
                            switchStartStatus[l] = 0;
                        } else {
                            switchStartStatus[l] = 1;
                        }
                    }
                }
            }

            output.write("#" + i + " " + switchCount +"\n");
        }
        input.close();
        output.close();
    }
}
