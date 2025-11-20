package baekJoon;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B12015 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];


        StringTokenizer st = new StringTokenizer(br.readLine());


        // 수열 입력 받을건데
        // '부분 수열' 이라서
        // 정렬하면 안된다.
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        // 값을 담을 배열
        List<Integer> lst = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {

            // 이번 이분탐색은
            // 답 배열의 인덱스다.
            int left = 0;
            int right = lst.size();
            
            // 인덱스로 값 꺼내서 비교
            while (left < right) {

                int mid = (left + right) / 2;

                // 현재 mid를 인덱스로 가지는 배열의 값이 현재 뽑아온 수보다 작으면
                // mid 보다 큰 값에서 수를 비교해야된다
                if (lst.get(mid) < arr[i]) {
                    left = mid + 1;
                    // 반대라면
                    // mid 위치에 같은값 or 작은수가 나올 수 있어서
                    // right = mid만.
                } else {
                    right = mid;
                }

            }
            
            // 결과 값을 현재 위치로 저장
            int currentPos = left;
            
            // 전체 사이즈보다 작으면
            // 해당위치 값 갱신
            if (currentPos < lst.size()) {
                lst.set(currentPos, arr[i]);
            } else {
                // 같거나 크면
                // 맨 뒤에 추가
                lst.add(arr[i]);
            }
        }

        int answer = lst.size();

        bw.write(String.valueOf(answer));


        bw.close();
        br.close();
    }


}
