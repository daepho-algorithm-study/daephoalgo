package baekJoon;

import java.io.*;

public class B1193 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int input = Integer.parseInt(br.readLine());
        
        // 지그재그인데 규칙이 있다면
        // 홀수 합으로 끝나는 경우 오른쪽 최상단 끝자리에 마지막 더해진 숫자가 들어감
        // 짝수 합으로 끝나는 경우 왼쪽 최하단 첫자리에 마지막 더해진 숫자가 들어감
        
        // 시작할 숫자
        // 3까진 해당 안됨
        int num = 3;

        int plusNum = 3;

        while (true) {

            if (input == 1) {
                bw.write(1 + "/" + 1);
                break;
            } else if (input == 2) {
                bw.write(1 + "/" + 2);
                break;
            } else if (input == 3) {
                bw.write(2 + "/" + 1);
                break;
            }


            int nextNum = num + plusNum;
            // 홀수 합으로 끝나는 경우 오른쪽 최상단 끝자리에 마지막 더해진 숫자가 들어감
            // 짝수 합으로 끝나는 경우 왼쪽 최하단 첫자리에 마지막 더해진 숫자가 들어감
            if (input == nextNum) {
                if (plusNum % 2 == 1) {
                    bw.write(1 + "/" + plusNum);
                    break;
                } else {
                    bw.write(plusNum + "/" + 1);
                    break;
                }

            } else if (input > num && nextNum > input) {
                // 홀수 합으로 끝나는 경우 오른쪽 최상단 끝자리에 마지막 더해진 숫자가 들어감
                // 그래서 차이만큼 첫자리에 더하고 뒷자리에서 뺀다
                if (plusNum % 2 == 1) {
                    bw.write((1 + (nextNum - input)) + "/" + (plusNum - (nextNum - input)));
                    break;
                    // 짝수 합으로 끝나는 경우 왼쪽 최하단 첫자리에 마지막 더해진 숫자가 들어감
                    // 차이만큼 뒷자리에 더하고 첫자리에서 뺀다
                } else {
                    bw.write((plusNum - (nextNum - input)) + "/" + (1 + (nextNum - input)));
                    break;
                }
            }

            num = nextNum;
            plusNum++;

        }


        bw.close();
        br.close();
    }


}

