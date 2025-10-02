package SWEA;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class S1860 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int test = 1; test <= tc; test++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            // 몇명이 붕어빵을 먹을 자격이 있는가
            // 붕어빵 만드는데 몇초가 걸리고
            // 만들어질때 한번에 몇개가 생산되는가

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            // 붕어빵 먹을 자격이 있는 사람의 도착정보를 저장할 배열
            int[] arr = new int[n];

            
            // 도착정보 저장중
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            // 도착정보 오름차순 정렬
            Arrays.sort(arr);

            // 큐를 이용하면 편할거 같아서 해봄
            Queue<Integer> customerInfo = new LinkedList<>();
            for (int i = 0; i < arr.length; i++) {
                customerInfo.add(arr[i]);
            }

            bw.write("#" + test + " ");

            // 큐에 남는게 없을때까지 돌린다
            // 초를 재는 변수, 빵의 갯수를 재는 변수
            // 시간을 1초씩 더하고 m과 흘러간 시간이 같아지면 빵개수 k개 증가, timeCount 리셋. totalTime 측정
            int totalTime = 0;
            int timeCount = 0;
            int bread = 0;
            boolean check = true;


            // 검증 시작
            while (!customerInfo.isEmpty()) {

                // 손님이 오픈런하면 불가능함;;
                if (customerInfo.peek() == 0) {
                    bw.write("Impossible" + "\n");
                    break;
                }

                timeCount++;
                totalTime++;

                if (m == timeCount) {
                    bread = bread + k;
                    timeCount = 0;
                }

                // 붕어빵 가지러 오는놈이 동시에 올 수도 있다.
                while (!customerInfo.isEmpty() && customerInfo.peek() == totalTime) {
                    if (bread == 0) {
                        check = false;
                        break;
                    }
                    bread--;
                    customerInfo.poll();
                }

                if (!check) {
                    bw.write("Impossible" + "\n");
                    break;
                }
                
                if (customerInfo.isEmpty()) {
                    bw.write("Possible" + "\n");
                    break;
                }
            }

        }


        bw.close();
        br.close();
    }


}


// 접근 방법은 맞는데 더 좋은 법이 있음
// 붕어빵 만드는데 걸리는 시간대에 손님 도착시간만 확인하는거임

// int breadCount = 0; // 지금까지 만들어진 붕어빵 수
//            int sec = 0;        // 붕어빵이 마지막으로 생산된 시각
//            boolean possible = true;
//
//            for (int arriveTime : arr) {
//                // 붕어빵을 손님 도착 시간까지 충분히 생산
//                while (sec + M <= arriveTime) {
//                    sec += M;
//                    breadCount += K;
//                }
//
//                // 붕어빵이 없으면 불가능
//                if (breadCount == 0) {
//                    possible = false;
//                    break;
//                }
//
//                // 손님에게 붕어빵 제공
//                breadCount--;
//            }
