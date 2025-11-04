package baekJoon;

import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class B2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 나무 자르기
        // n개의 나무를 어느 높이에서 잘라야 처음으로 m이랑 같거나 커지는가?
        // 당연히 for 문 돌리면 터질거라 생각함
        // 이진 탐색

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] treeArr = new int[n];
        // 이진 탐색의 right를 맡아줄 부분, 최대높이
        int maxTreeLength = Integer.MIN_VALUE;

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < treeArr.length; i++) {
            treeArr[i] = Integer.parseInt(st.nextToken());
            if (treeArr[i] > maxTreeLength) {
                maxTreeLength = treeArr[i];
            }
        }

        int left = 0;
        int right = maxTreeLength;
        int answer = 0;

        // 이진 탐색
        // 핵심 조건 왼쪽은 오른쪽보다 커질 수 없다.
        while (left <= right) {

            int mid = (left + right) / 2;

            // 이거 안해도 틀림;;
            // 범위가 넓어서 해당범위 최대치로 돌리면 10에 15승임
            // int 범위 : -2,147,483,648 ~ 2,147,483,647
            // 자세히는 몰라도 10에 15승은 가뿐히 넘는다 해당 범위를
            // long을 사용해서 풀어야함.
            long totalTreeLength = 0;

            for (int i = 0; i < treeArr.length; i++) {
                if (treeArr[i] - mid > 0) {
                    totalTreeLength += treeArr[i] - mid;
                }
            }

            // 잘라서 봤는데
            // 같거나 커요
            // 이 높이에서는 맞을수도 있고 넉넉할 수도 있으니까
            // 해당높이 포함 밑으로는 보지말자!
            if (totalTreeLength >= m) {
                // 일단 해당 높이를 킵은 해야됨
                answer = mid;
                // 이 높이보다 1 올려서 다시한번 확인해봐
                left = mid + 1;
            } else {
                // 잘라서 봤는데
                // 작아요 높이를 낮춰서 더 잘라야되요
                // 이 높이에서는 작으니까?
                // 해당 높이 포함 위로는 안봐도 된다!
                // 이 높이에서 1을 빼고 다시 돌려보자!
                right = mid - 1;
            }

        }



        bw.write(String.valueOf(answer));




        bw.close();
        br.close();
    }


}
