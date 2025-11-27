package baekJoon;


import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B2470 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // 두 용액
        
        // 용액 갯수
        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        
        // 용액 값 배열 저장
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            arr[i] = Integer.parseInt(st.nextToken());

        }
        
        // 이번 문제의 경우 정렬이 필수임
        // 아래에서 설명해야됨
        Arrays.sort(arr);
        
        // 투포인터 변수 값, 비교 값, 양쪽 합, 답으로 쓸 좌우값 담을 2개 변수
        int left = 0;
        int right = n - 1;
        int num = Integer.MAX_VALUE;
        int sum = 0;

        int answerLeft = 0;
        int answerRight = 0;

        
        while (left < right) {
            
            // 더한다
            sum = arr[left] + arr[right];

            // 합의 절대값이 현재 num의 절댓값 보다 작으면
            // 좌 우 값을 저장하고
            // 현재 num 값에 지금 조합의 합을 지정
            if (Math.abs(sum) < Math.abs(num)) {
                answerLeft = arr[left];
                answerRight = arr[right];
                num = sum;
            }

            // 이걸 위해서 우린 정렬을 했다.
            // 합이 크다?
            // 오른쪽 포인터를 한칸 줄여서 다시 봐보자
            if (sum > 0) {
                right--;
                // 합이 0보다 작다?
                // 왼쪽 포인터를 한칸 올려서 다시 봐보자
            } else if (sum < 0) {
                left++;
            } else {
                // 같으면?
                // 끝내면 되지!
                break;
            }


        }



        bw.write(String.valueOf(answerLeft + " " + answerRight));








        bw.close();
        br.close();
    }


}

