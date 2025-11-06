package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class B14626 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        // ISBN
        // 13개 숫자에 1 3 이 순서대로 가중치를 곱한 다음
        // 해당 수들을 모두 더해서 10으로 나눈다.
        // 그럼 0이 되어야 한다. 이때 0이 되도록 만드는 숫자는 마지막자리 숫자이다. 이것을 체크기호라고 한다.

        // 값 받고 가중치만큼 곱해서 더한다.
        // 이때 * 자리는 인덱스를 체크해놓는다.

        String input = br.readLine();

        char[] arr = input.toCharArray();

        int index = 0;

        int num = 0;

        int answer = 0;
        
        // 빈자리 찾고 해당 빈자리가 어떤 가중치를 가질지 판별하기 위해
        for (int i = 0; i < arr.length; i++) {
            // *이 빈자리임
            if (String.valueOf(arr[i]).equals("*")) {
                index = i + 1;
                continue;
            }

            // 홀수, 가중치 1
            if ((i + 1) % 2 == 1) {
                num = num + 1 * Integer.parseInt(String.valueOf(arr[i]));
            } else {
                // 짝수, 가중치 3
                num = num + 3 * Integer.parseInt(String.valueOf(arr[i]));
            }
        }

        // *을 제외한 모든 값의 합을 10으로 나눈다
        // 해당 값은 (10 - 나머지)를 *의 1의 자리가 메꾸고 그로 인해 10의 배수가 된다
        // * = (10 - (num % 10))을 1의 자리로 가지는 숫자란 소리다

        // 인덱스가 짝수면 가중치가 3
        // 3의 배수중 (10 - (num % 10)) 를 1의 자리로 가지는 숫자가 정답이다.
        if (index % 2 == 0) {
            // 이거 1에서 9까지 돌렸는데도 통과함
            // 0일 경우 처리못할텐데?
            for (int i = 0; i < 10; i++) {
                if ((3 * i) % 10 == (10 - (num % 10))) {
                    answer = i;
                    break;
                }
            }
        } else {
            // 인덱스가 홀수면 가중치가 1
            // *의 값을 그자체 그대로 가져간다
            answer = (10 - (num % 10)) % 10;

            // 이거 왜 됨? 10인데?
            //  answer = (10 - (num % 10)) / 1;
        }

        bw.write(String.valueOf(answer));

        bw.close();
        br.close();
    }


}