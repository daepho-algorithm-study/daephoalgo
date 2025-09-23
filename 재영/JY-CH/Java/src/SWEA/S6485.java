package SWEA;

import java.io.*;
import java.util.StringTokenizer;

public class S6485 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int i = 1; i <= tc; i++) {

            bw.write("#" + i);

            // 노선 갯수
            int line = Integer.parseInt(br.readLine());

            // 노선 저장용, 출발 도착역에 대한 정보를 순차적으로 받아 2차원 배열에 저장할 생각
            int[][] busLine = new int[line][2];

            for (int j = 0; j < line; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 2; k++) {
                    busLine[j][k] = Integer.parseInt(st.nextToken());
                }
            }

            // 확인해야할 역의 갯수
            int stationNumber = Integer.parseInt(br.readLine());

            // 해당역의 정보를 받아오고
            // 그 역들이 노선 안에 있는지 체크해야됨.
            for (int l = 0; l < stationNumber; l++) {
                int cnt = 0;
                int targetStation = Integer.parseInt(br.readLine());
                int startStation = 0;
                int endStation = 0;

                for (int p = 0; p < line; p++) {
                    startStation = busLine[p][0];
                    endStation = busLine[p][1];

                    if (startStation <= targetStation && endStation >= targetStation) {
                        cnt++;
                    }
                }

                bw.write(" " + cnt);

            }
            bw.write("\n");

        }
        br.close();
        bw.close();
    }
}


// 누적합을 이용한 방법이 더 빠르다
// for (int tc = 1; tc <= T; tc++) {
            // 버스 노선 5000개까지라서 받음
//            int[] count = new int[5001];
//
//            int N = Integer.parseInt(br.readLine());
//            // 정류장 정보를 받고
//            for (int i = 0; i < N; i++) {
//                StringTokenizer st = new StringTokenizer(br.readLine());
//                int A = Integer.parseInt(st.nextToken());
//                int B = Integer.parseInt(st.nextToken());
//           // 시작 정류장 번호에 1을 더하고
//           // 끝나는 정류장 "다음" 정류장에 1을 깍는다
//                count[A] += 1;
//                if (B + 1 <= 5000) {
//                    count[B + 1] -= 1;
//                }
//            }

            //index:  0 1 2 3 4 5 6
            //count:  0 1 1 0 -1 0 -1
//
//            // 누적합 수행
//            for (int i = 1; i <= 5000; i++) {
//                count[i] += count[i - 1];
//            }

//            i	count[i] (누적합) 설명
//        1	count[1] = count[1] + count[0] = 1 + 0 = 1 (버스 1대 지나가요)
//        2	1 + 1 = 2 (여긴 버스 2대 지나가요)
//        3	2 + 0 = 2 (여기도 2대 다녀요)
//        4	2 + (-1) = 1 (아까 버스 1대가 빠져서 1대만 여길 지나요)
//        5	1 + 0 = 1
//        6	1 + (-1) = 0 (전 정류장에서 버스가 끊겼으니 아무것도 없어요
//        정류장:    1 2 3 4 5 6
//        버스 수:   1 2 2 1 1 0

//
//            // 질의 처리
//            int P = Integer.parseInt(br.readLine());
//            bw.write("#" + tc);
//
//            for (int i = 0; i < P; i++) {
//                int C = Integer.parseInt(br.readLine());
//                bw.write(" " + count[C]);
//            }
//
//            bw.write("\n");
//        }
//
//        br.close();
//        bw.close();
//    }
